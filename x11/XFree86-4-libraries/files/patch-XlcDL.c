--- lib/X11/XlcDL.c.orig	Sun Dec  1 23:17:32 2002
+++ lib/X11/XlcDL.c	Sun Dec  1 23:17:11 2002
@@ -60,7 +60,12 @@
 #define	_MACH64_NAME		"sparcv9"
 #define	_MACH64_NAME_LEN	(sizeof (_MACH64_NAME) - 1)
 #else  /* !defined(__sparcv9) */
+#if defined(__ia64__)
+#define _MACH64_NAME		"ia64"
+#define _MACH64_NAME_LEN        (sizeof (_MACH64_NAME) - 1)
+#else  /* !defined(__ia64__) */
 #error "Unknown architecture"
+#endif /* defined(__ia64__) */
 #endif /* defined(__sparcv9) */
 #endif /* _LP64 */
 
@@ -83,6 +83,7 @@
   char *im_register;
   char *im_unregister;
   int dl_release;
+  unsigned int refcount;
 #if defined(hpux)
   shl_t dl_module;
 #else
@@ -214,6 +215,7 @@
 	  xi18n_objects_list[lc_count].open = strdup(args[2]);
 	  xi18n_objects_list[lc_count].dl_release = XI18N_DLREL;
 	  xi18n_objects_list[lc_count].locale_name = strdup(lc_name);
+	  xi18n_objects_list[lc_count].refcount = 0;
 	  xi18n_objects_list[lc_count].dl_module = (void*)NULL;
 	  if (n == 5) {
 	    xi18n_objects_list[lc_count].im_register = strdup(args[3]);
@@ -290,6 +292,85 @@
     return path;
 }
 
+/* We reference count dlopen() and dlclose() of modules; unfortunately,
+ * since XCloseIM, XCloseOM, XlcClose aren't wrapped, but directly
+ * call the close method of the object, we leak a reference count every
+ * time we open then close a module. Fixing this would require
+ * either creating proxy objects or hooks for close_im/close_om
+ * in XLCd
+ */
+static Bool
+open_object (object, lc_dir)
+     XI18NObjectsList object;
+     char *lc_dir;
+{
+  char *path;
+
+  if (object->refcount == 0) {
+      path = __lc_path(object->dl_name, lc_dir);
+#if defined(hpux)
+      object->dl_module = shl_load(path, BIND_DEFERRED, 0L);
+#else
+      object->dl_module = dlopen(path, RTLD_LAZY);
+#endif
+      Xfree(path);
+
+      if (!object->dl_module)
+         return False;
+    }
+
+  object->refcount++;
+  return True;
+}
+
+static void *
+fetch_symbol (object, symbol)
+     XI18NObjectsList object;
+     char *symbol;
+{
+    void *result = NULL;
+#if defined(hpux)
+    int getsyms_cnt, i;
+    struct shl_symbol *symbols;
+#endif
+
+#if defined(hpux)
+    getsyms_cnt = shl_getsymbols(object->dl_module, TYPE_PROCEDURE,
+                                EXPORT_SYMBOLS, malloc, &symbols);
+
+    for(i=0; i<getsyms_cnt; i++) {
+        if(!strcmp(symbols[i].name, symbol)) {
+           result = symbols[i].value;
+           break;
+         }
+    }
+
+    if(getsyms_cnt > 0) {
+        free(symbols);
+    }
+#else
+    result = (XLCd(*)())try_both_dlsym(object->dl_module, symbol);
+#endif
+
+    return result;
+}
+
+static void
+close_object (object)
+     XI18NObjectsList object;
+{
+  object->refcount--;
+  if (object->refcount == 0)
+    {
+#if defined(hpux)
+        shl_unload(object->dl_module);
+#else
+        dlclose(object->dl_module);
+#endif
+        object->dl_module = NULL;
+    }
+}
+
 XLCd
 #if NeedFunctionPrototypes
 _XlcDynamicLoad(const char *lc_name)
@@ -300,14 +381,9 @@
 {
     XLCd lcd = (XLCd)NULL;
     XLCd (*lc_loader)() = (XLCd(*)())NULL;
-    char *path;
     int count;
     XI18NObjectsList objects_list;
     char lc_dir[BUFSIZE];
-#if defined(hpux)
-    int getsyms_cnt, i;
-    struct shl_symbol *symbols;
-#endif
 
     if (lc_name == NULL) return (XLCd)NULL;
 
@@ -321,47 +397,17 @@
     for (; count-- > 0; objects_list++) {
         if (objects_list->type != XLC_OBJECT ||
 	    strcmp(objects_list->locale_name, lc_name)) continue;
-	if (!objects_list->dl_module) {
-	  path = __lc_path(objects_list->dl_name, lc_dir);
-	  if (!path)
-	      continue;
-#if defined(hpux)
-	  objects_list->dl_module = shl_load(path, BIND_DEFERRED, 0L);
-#else
-	  objects_list->dl_module = dlopen(path, RTLD_LAZY);
-#endif
-	  Xfree(path);
-	  if (!objects_list->dl_module) continue;
-	}
-#if defined(hpux)
-	getsyms_cnt = shl_getsymbols(objects_list->dl_module, TYPE_PROCEDURE,
-		EXPORT_SYMBOLS, malloc, &symbols);
-
-	for(i=0; i<getsyms_cnt; i++) {
-	    if(!strcmp(symbols[i].name, objects_list->open)) {
-		lc_loader = symbols[i].value;
-		break;
-	    }
-	}
+	if (!open_object (objects_list, lc_dir))
+	  continue;
 
-	if(getsyms_cnt > 0) {
-	    free(symbols);
-	}
-#else
-	lc_loader = (XLCd(*)())try_both_dlsym(objects_list->dl_module,
-					      objects_list->open);
-#endif
+	lc_loader = (XLCd(*)())fetch_symbol (objects_list, objects_list->open);
 	if (!lc_loader) continue;
 	lcd = (*lc_loader)(lc_name);
 	if (lcd != (XLCd)NULL) {
 	    break;
 	}
-#if defined(hpux)
-	shl_unload(objects_list->dl_module);
-#else
-	dlclose(objects_list->dl_module);
-#endif
-	objects_list->dl_module = NULL;
+       
+	close_object (objects_list);
     }
     return (XLCd)lcd;
 }
@@ -379,16 +425,11 @@
 #endif
 {
   XIM im = (XIM)NULL;
-  char *path;
   char lc_dir[BUFSIZE];
   char *lc_name;
   XIM (*im_openIM)() = (XIM(*)())NULL;
   int count;
   XI18NObjectsList objects_list = xi18n_objects_list;
-#if defined(hpux)
-  int getsyms_cnt, i;
-  struct shl_symbol *symbols;
-#endif
 
   lc_name = lcd->core->name;
 
@@ -398,48 +439,18 @@
   for (; count-- > 0; objects_list++) {
     if (objects_list->type != XIM_OBJECT ||
 	strcmp(objects_list->locale_name, lc_name)) continue;
-    if (!objects_list->dl_module) {
-      path = __lc_path(objects_list->dl_name, lc_dir);
-      if (!path)
-	  continue;
-#if defined(hpux)
-      objects_list->dl_module = shl_load(path, BIND_DEFERRED, 0L);
-#else
-      objects_list->dl_module = dlopen(path, RTLD_LAZY);
-#endif
-      Xfree(path);
-      if (!objects_list->dl_module) continue;
-    }
-#if defined(hpux)
-    getsyms_cnt = shl_getsymbols(objects_list->dl_module, TYPE_PROCEDURE,
-	EXPORT_SYMBOLS, malloc, &symbols);
 
-    for(i=0; i<getsyms_cnt; i++) {
-	if(!strcmp(symbols[i].name, objects_list->open)) {
-	    im_openIM = symbols[i].value;
-	    break;
-	}
-     }
+    if (!open_object (objects_list, lc_dir))
+      continue;
 
-    if(getsyms_cnt > 0) {
-	free(symbols);
-    }
-#else
-    im_openIM = (XIM(*)())try_both_dlsym(objects_list->dl_module,
-					 objects_list->open);
+    im_openIM = (XIM(*)())fetch_symbol(objects_list, objects_list->open);
     if (!im_openIM) continue;
-#endif
     im = (*im_openIM)(lcd, display, rdb, res_name, res_class);
     if (im != (XIM)NULL) {
       break;
     }
-    im_openIM = 0;
-#if defined(hpux)
-    shl_unload(objects_list->dl_module);
-#else
-    dlclose(objects_list->dl_module);
-#endif
-    objects_list->dl_module = NULL;
+
+    close_object (objects_list);
   }
   return (XIM)im;
 }
@@ -455,7 +466,6 @@
 XIMProc	 callback;
 XPointer	*client_data;
 {
-  char *path;
   char lc_dir[BUFSIZE];
   char *lc_name;
   Bool (*im_registerIM)() = (Bool(*)())NULL;
@@ -475,49 +485,18 @@
   for (; count-- > 0; objects_list++) {
     if (objects_list->type != XIM_OBJECT ||
 	strcmp(objects_list->locale_name, lc_name)) continue;
-    if (!objects_list->dl_module) {
-      path = __lc_path(objects_list->dl_name, lc_dir);
-      if (!path)
-	  continue;
-#if defined(hpux)
-      objects_list->dl_module = shl_load(path, BIND_DEFERRED, 0L);
-#else
-      objects_list->dl_module = dlopen(path, RTLD_LAZY);
-#endif
-      Xfree(path);
-      if (!objects_list->dl_module) continue;
-    }
-#if defined(hpux)
-    getsyms_cnt = shl_getsymbols(objects_list->dl_module, TYPE_PROCEDURE,
-	EXPORT_SYMBOLS, malloc, &symbols);
-
-    for(i=0; i<getsyms_cnt; i++) {
-	if(!strcmp(symbols[i].name, objects_list->open)) {
-	    im_registerIM = symbols[i].value;
-	    break;
-	}
-     }
 
-    if(getsyms_cnt > 0) {
-	free(symbols);
-    }
-#else
-    im_registerIM = (Bool(*)())try_both_dlsym(objects_list->dl_module,
-					      objects_list->im_register);
+    if (!open_object (objects_list, lc_dir))
+      continue;
+    im_registerIM = (Bool(*)())fetch_symbol(objects_list,
+					    objects_list->im_register);
     if (!im_registerIM) continue;
-#endif
     ret_flag = (*im_registerIM)(lcd, display, rdb,
 				res_name, res_class,
 				callback, client_data);
     if (ret_flag) break;
 
-    im_registerIM = 0;
-#if defined(hpux)
-    shl_unload(objects_list->dl_module);
-#else
-    dlclose(objects_list->dl_module);
-#endif
-    objects_list->dl_module = NULL;
+    close_object (objects_list);
   }
   return (Bool)ret_flag;
 }
@@ -533,7 +512,6 @@
 XIMProc	 callback;
 XPointer	*client_data;
 {
-  char *path;
   char lc_dir[BUFSIZE];
   char *lc_name;
   Bool (*im_unregisterIM)() = (Bool(*)())NULL;
@@ -552,50 +530,21 @@
   for (; count-- > 0; objects_list++) {
     if (objects_list->type != XIM_OBJECT ||
 	strcmp(objects_list->locale_name, lc_name)) continue;
-    if (!objects_list->dl_module) {
-      path = __lc_path(objects_list->dl_name, lc_dir);
-      if (!path)
-	  continue;
-#if defined(hpux)
-      objects_list->dl_module = shl_load(path, BIND_DEFERRED, 0L);
-#else
-      objects_list->dl_module = dlopen(path, RTLD_LAZY);
-#endif
-      Xfree(path);
-      if (!objects_list->dl_module) continue;
-    }
-#if defined(hpux)
-    getsyms_cnt = shl_getsymbols(objects_list->dl_module, TYPE_PROCEDURE,
-	EXPORT_SYMBOLS, malloc, &symbols);
 
-    for(i=0; i<getsyms_cnt; i++) {
-	if(!strcmp(symbols[i].name, objects_list->open)) {
-	    im_unregisterIM = symbols[i].value;
-	    break;
-	}
-     }
+    if (!objects_list->refcount) /* Must already be opened */
+      continue;
 
-    if(getsyms_cnt > 0) {
-	free(symbols);
-    }
-#else
-    im_unregisterIM = (Bool(*)())try_both_dlsym(objects_list->dl_module,
-						objects_list->im_unregister);
+    im_unregisterIM = (Bool(*)())fetch_symbol(objects_list,
+					      objects_list->im_unregister);
 
     if (!im_unregisterIM) continue;
-#endif
     ret_flag = (*im_unregisterIM)(lcd, display, rdb,
 				  res_name, res_class,
 				  callback, client_data);
-    if (ret_flag) break;
-
-    im_unregisterIM = 0;
-#if defined(hpux)
-    shl_unload(objects_list->dl_module);
-#else
-    dlclose(objects_list->dl_module);
-#endif
-    objects_list->dl_module = NULL;
+    if (ret_flag) {
+      close_object (objects_list); /* opened in RegisterIMInstantiateCallback */
+      break;
+    }
   }
   return (Bool)ret_flag;
 }
@@ -631,7 +580,6 @@
 {
   XOM om = (XOM)NULL;
   int count;
-  char *path;
   char lc_dir[BUFSIZE];
   char *lc_name;
   XOM (*om_openOM)() = (XOM(*)())NULL;
@@ -649,48 +597,16 @@
   for (; count-- > 0; objects_list++) {
     if (objects_list->type != XOM_OBJECT ||
 	strcmp(objects_list->locale_name, lc_name)) continue;
-    if (!objects_list->dl_module) {
-      path = __lc_path(objects_list->dl_name, lc_dir);
-      if (!path)
-	  continue;
-#if defined(hpux)
-      objects_list->dl_module = shl_load(path, BIND_DEFERRED, 0L);
-#else
-      objects_list->dl_module = dlopen(path, RTLD_LAZY);
-#endif
-      Xfree(path);
-      if (!objects_list->dl_module) continue;
-    }
-#if defined(hpux)
-    getsyms_cnt = shl_getsymbols(objects_list->dl_module, TYPE_PROCEDURE,
-	EXPORT_SYMBOLS, malloc, &symbols);
-
-    for(i=0; i<getsyms_cnt; i++) {
-	if(!strcmp(symbols[i].name, objects_list->open)) {
-	    om_openOM = symbols[i].value;
-	    break;
-	}
-     }
-
-    if(getsyms_cnt > 0) {
-	free(symbols);
-    }
-#else
-    om_openOM = (XOM(*)())try_both_dlsym(objects_list->dl_module,
-					 objects_list->open);
+    if (!open_object (objects_list, lc_dir))
+      continue;
+    
+    om_openOM = (XOM(*)())fetch_symbol(objects_list, objects_list->open);
     if (!om_openOM) continue;
-#endif
     om = (*om_openOM)(lcd, display, rdb, res_name, res_class);
     if (om != (XOM)NULL) {
       break;
     }
-    om_openOM = 0;
-#if defined(hpux)
-    shl_unload(objects_list->dl_module);
-#else
-    dlclose(objects_list->dl_module);
-#endif
-    objects_list->dl_module = NULL;
+    close_object(objects_list);
   }
   return (XOM)om;
 }
