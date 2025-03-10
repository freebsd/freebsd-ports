--- xseticon.c.orig	2018-01-15 20:20:01 UTC
+++ xseticon.c
@@ -46,6 +46,7 @@ void usage(int exitcode)
   printf("options:\n");
   printf("  -name <text>    : apply icon to the window of the name supplied\n");
   printf("  -id <windowid>  : apply icon to the window id supplied\n");
+  printf("  -class <text>   : apply icon to the window matching the class supplied\n");
   printf("\n");
   printf("Sets the window icon to the specified .png image. The image is loaded from\n");
   printf("the file at runtime and sent to the X server; thereafter the file does not\n");
@@ -98,6 +99,30 @@ Window Window_With_Name(Display* dpy, Window top, char
   return(w);
 }
 
+Window Window_With_Class(Display* dpy, Window top, char* class)
+{
+  Window *children, dummy;
+  unsigned int nchildren;
+  int i;
+  Window w = 0;
+  XClassHint *hint = XAllocClassHint();
+
+  if (XGetClassHint(dpy, top, hint)
+      && (!strcmp(hint->res_class, class) || !strcmp(hint->res_name, class)))
+    return(top);
+
+  if (!XQueryTree(dpy, top, &dummy, &dummy, &children, &nchildren))
+    return(0);
+
+  for (i=0; i<nchildren; i++) {
+          w = Window_With_Class(dpy, children[i], class);
+          if (w)
+            break;
+  }
+  if (children) XFree ((char *)children);
+  return(w);
+}
+
 Window Select_Window_Args(Display* dpy, int screen, int* rargc, char* argv[])
 {
   int nargc = 1;
@@ -127,6 +152,16 @@ Window Select_Window_Args(Display* dpy, int screen, in
                            OPTION);
       if (!w)
         Fatal_Error("No window with name %s exists!",OPTION);
+      continue;
+    }
+    if (!strcmp(OPTION, "-class")) {
+      NXTOPT;
+      if (verbose)
+        printf("Selecting window by class %s\n", OPTION);
+      w = Window_With_Class(dpy, RootWindow(dpy, screen),
+                            OPTION);
+      if (!w)
+        Fatal_Error("No window with class %s exists!",OPTION);
       continue;
     }
     if (!strcmp(OPTION, "-id")) {
