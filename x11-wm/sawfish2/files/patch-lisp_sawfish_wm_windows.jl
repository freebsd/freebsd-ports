--- lisp/sawfish/wm/windows.jl.orig	Thu Feb 13 12:54:55 2003
+++ lisp/sawfish/wm/windows.jl	Thu Feb 13 12:55:33 2003
@@ -320,7 +320,7 @@
 	    (t x))))
 
   (define (adjust-position-for-gravity/y w grav y #!key inverse)
-    (let* ((tl-off (window-frame-offset w))
+      (let* ((tl-off (cdr (window-frame-offset w)))
 	   (br-off (- (cdr (window-frame-dimensions w))
 		      (cdr (window-dimensions w))))
 	   (sign (if inverse -1 +1)))
