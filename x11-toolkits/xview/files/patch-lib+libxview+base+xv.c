--- lib/libxview/base/xv.c.orig	Wed May  5 15:38:10 2004
+++ lib/libxview/base/xv.c	Wed May  5 15:40:31 2004
@@ -556,7 +556,11 @@
 	case XV_KEY_DATA:
 	case XV_IS_SUBTYPE_OF:
 	    status = XV_OK;
+#ifdef __amd64__
+	    va_copy(args,args_save);
+#else
 	    args = args_save;
+#endif
 	    result = generic_get(object, &status, (Attr_attribute) attr, args);
 	    va_end(args);
 	    return result;
@@ -575,7 +579,11 @@
 	 * Go to the beginning of the varargs list every time to insure each
          * pkg gets the start of the  varargs.
 	 */
+#ifdef __amd64__
+        va_copy(args,args_save);
+#else
         args = args_save;
+#endif
 
 	/* ask the object to handle the get */
 	result = (*(pkg->get)) (object, &status, (Attr_attribute) attr, args);
