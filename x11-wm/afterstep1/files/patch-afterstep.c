--- afterstep/afterstep.c.orig	1997-05-04 15:19:57 UTC
+++ afterstep/afterstep.c
@@ -147,7 +147,7 @@ char *display_name = NULL;
  *
  ***********************************************************************
  */
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
     unsigned long valuemask;	/* mask for create windows */
     XSetWindowAttributes attributes;	/* attributes for create windows */
@@ -463,7 +463,7 @@ void main(int argc, char **argv)
 
     XDefineCursor(dpy, Scr.Root, Scr.ASCursors[DEFAULT]);
     HandleEvents();
-    return;
+    return 0;
 }
 
 /***********************************************************************
@@ -787,7 +787,7 @@ void InitModifiers(void)
           for (i = 0; i < mm->max_keypermod; i++)
             {
       	if ((kc = *kp++) &&
-      	    ((ks = XKeycodeToKeysym(dpy, kc, 0)) != NoSymbol))
+      	    ((ks = XkbKeycodeToKeysym(dpy, kc, 0, 0)) != NoSymbol))
       	  {
       	    kn = XKeysymToString(ks);
       	    knl = strlen(kn);
