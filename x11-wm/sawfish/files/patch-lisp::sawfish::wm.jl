
$FreeBSD$

--- lisp/sawfish/wm.jl.orig	Tue May  7 06:35:59 2002
+++ lisp/sawfish/wm.jl	Mon Jul  1 11:16:13 2002
@@ -46,8 +46,8 @@
     (when (and lang (not disable-nls) (not (string= lang "C")))
       (require 'rep.i18n.gettext)
       (bindtextdomain "sawfish" sawfish-locale-directory)
-      (when (boundp 'bindtextdomaincodeset)
-	(bindtextdomaincodeset "sawfish" "UTF-8"))
+;;      (when (boundp 'bindtextdomaincodeset)
+;;	(bindtextdomaincodeset "sawfish" "UTF-8"))
       (textdomain "sawfish"))))
 
 ;; ignore file errors on stdio streams
