--- pTk/Xlib.t.orig	2023-05-19 20:18:20 UTC
+++ pTk/Xlib.t
@@ -331,7 +331,7 @@ VFUNC(int,XIntersectRegion,V_XIntersectRegion,_ANSI_AR
 #endif /* !DO_X_EXCLUDE */
 
 #ifndef XKeycodeToKeysym
-VFUNC(KeySym,XKeycodeToKeysym,V_XKeycodeToKeysym,_ANSI_ARGS_((Display *, unsigned int, int)))
+VFUNC(KeySym,XKeycodeToKeysym,V_XKeycodeToKeysym,_ANSI_ARGS_((Display *, KeyCode, int)))
 #endif /* #ifndef XKeycodeToKeysym */
 
 #ifndef XKeysymToString
