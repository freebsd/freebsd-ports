--- lisp/sawfish/wm/state/wm-spec.jl.orig	Sun Sep 28 22:51:20 2003
+++ lisp/sawfish/wm/state/wm-spec.jl	Sun Sep 28 22:52:10 2003
@@ -125,7 +125,7 @@
      _NET_WM_WINDOW_TYPE_UTILITY
      _NET_WM_WINDOW_TYPE_SPLASH])
   
-  (defvar wm-spec-below-depth +2)
+  (defvar wm-spec-below-depth -2)
   (defvar wm-spec-above-depth +2)
 
   (define supported-states '())
