--- lisp/sawfish/wm/gnome/integration.jl.orig	Sat May 25 15:55:29 2002
+++ lisp/sawfish/wm/gnome/integration.jl	Sat May 25 15:55:31 2002
@@ -19,8 +19,6 @@
 ;; along with sawmill; see the file COPYING.  If not, write to
 ;; the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 
-(eval-when-compile (require 'sawfish.wm.commands.xterm))
-
 (define-structure sawfish.wm.gnome.integration ()
 
     (open rep
@@ -28,7 +26,8 @@
 	  sawfish.wm.gnome.menus
 	  sawfish.wm.menus
 	  sawfish.wm.custom
-	  sawfish.wm.commands.help)
+	  sawfish.wm.commands.help
+	  sawfish.wm.commands.xterm)
 
   (define-structure-alias gnome-int sawfish.wm.gnome.integration)
 
@@ -46,6 +45,7 @@
   (put 'gnome-use-capplet 'custom-obsolete t)
 
   ;; invoke the GNOME terminal instead of xterm
+  (eval-when-compile (require 'sawfish.wm.commands.xterm))
   (unless (variable-customized-p 'xterm-program)
     (setq xterm-program "gnome-terminal"))
 
