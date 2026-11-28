--- stumpwm.asd.orig	2026-11-28 00:04:49 UTC
+++ stumpwm.asd
@@ -7,7 +7,7 @@
 (defsystem :stumpwm
   :name "StumpWM"
   :author "Shawn Betts <sabetts@vcn.bc.ca>"
-  :version "24.11"
+  :version "26.11"
   :maintainer "David Bjergaard <dbjergaard@gmail.com>"
   ;; :license "GNU General Public License"
   :description "A tiling, keyboard driven window manager"
@@ -17,8 +17,7 @@
                #:clx
                #:sb-posix
                #:sb-introspect
-               #:dynamic-mixins-swm
-               #:dbus)
+               #:dynamic-mixins-swm)
   :components ((:file "package")
                (:file "debug")
                (:file "primitives")
