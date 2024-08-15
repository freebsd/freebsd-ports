--- afterstep/configure.c.orig	1997-03-09 00:43:54 UTC
+++ afterstep/configure.c
@@ -2090,7 +2090,7 @@ void AddFuncKey (char *name, int cont, int mods, int f
  
   XDisplayKeycodes(dpy, &min, &max);
   for (i=min; i<=max; i++)
-    if (XKeycodeToKeysym(dpy, i, 0) == keysym)
+    if (XkbKeycodeToKeysym(dpy, i, 0, 0) == keysym)
       {
 	tmp = (FuncKey *) safemalloc(sizeof(FuncKey));
 	tmp->next = Scr.FuncKeyRoot.next;
