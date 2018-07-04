--- lib_radare2.pri.orig	2018-07-03 16:26:29 UTC
+++ lib_radare2.pri
@@ -38,7 +38,9 @@ win32 {
     macx {
         PREFIX=/usr/local
     } else {
-        PREFIX=/usr
+        isEmpty(PREFIX) {
+            PREFIX = /usr/local
+        }
     }
     USE_PKGCONFIG = 1
     R2_USER_PKGCONFIG = $$(HOME)/bin/prefix/radare2/lib/pkgconfig
