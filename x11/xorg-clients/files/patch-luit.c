--- programs/luit/luit.c.orig	Sat May 29 17:14:45 2004
+++ programs/luit/luit.c	Sat May 29 17:15:01 2004
@@ -549,9 +549,10 @@
     if(rc < 0)
         FatalError("Couldn't copy terminal settings\n");
 
-    rc = setRawTermios();
+    /*rc = setRawTermios();
     if(rc < 0)
         FatalError("Couldn't set terminal to raw\n");
+    */		/* Disabled, appears to break luit. */
 
     val = fcntl(0, F_GETFL, 0);
     if(val >= 0) {
