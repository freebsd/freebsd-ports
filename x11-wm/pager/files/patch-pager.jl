--- pager.jl.orig	Tue Nov 19 21:06:10 2002
+++ pager.jl	Tue Nov 19 21:08:30 2002
@@ -277,7 +277,10 @@
   ;; Tells the C program to change the colors
   (define (send-colors)
     (send ?c
-	  (mapcar color-rgb
+	  (mapcar (lambda (color)
+                     (let ((clist (color-rgb color)))
+                        (setcdr (nthcdr 2 clist) nil)
+                        clist))
 		  (list pager-color-background
 			pager-color-viewport
 			pager-color-window
