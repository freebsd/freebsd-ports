
$FreeBSD$

--- lisp/sawfish/ui/i18n.jl	2002/07/01 07:59:43	1.1
+++ lisp/sawfish/ui/i18n.jl	2002/07/01 07:59:56
@@ -59,6 +59,6 @@
       (let ((locale-dir (wm-locale-dir)))
 	(when locale-dir
 	  (bindtextdomain "sawfish" locale-dir)
-	  (when (boundp 'bindtextdomaincodeset)
-	    (bindtextdomaincodeset "sawfish" "UTF-8"))
+;;	  (when (boundp 'bindtextdomaincodeset)
+;;	    (bindtextdomaincodeset "sawfish" "UTF-8"))
 	  (textdomain "sawfish"))))))
