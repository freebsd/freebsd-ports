--- modules/Wharf/Wharf.c.orig	1997-03-19 01:28:51 UTC
+++ modules/Wharf/Wharf.c
@@ -191,7 +191,7 @@ void FindLockMods(void);
  *
  ***********************************************************************
  */
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
   char *display_name = NULL;
   int i,j;
@@ -2267,7 +2267,7 @@ void FindLockMods(void)
           for (i = 0; i < mm->max_keypermod; i++)
             {
       	if ((kc = *kp++) &&
-      	    ((ks = XKeycodeToKeysym(dpy, kc, 0)) != NoSymbol))
+      	    ((ks = XkbKeycodeToKeysym(dpy, kc, 0, 0)) != NoSymbol))
       	  {
       	    kn = XKeysymToString(ks);
       	    knl = strlen(kn);
@@ -2433,7 +2433,7 @@ void ConstrainSize (XSizeHints *hints, int *widthp, in
   
   *widthp = dwidth;
   *heightp = dheight;
-  return;
+  return 0;
 }
 
 
