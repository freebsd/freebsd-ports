--- ext/gtkhtml/config.m4.orig	Thu Apr 11 04:19:46 2002
+++ ext/gtkhtml/config.m4	Sat Dec  7 21:16:19 2002
@@ -21,7 +21,7 @@
   AC_MSG_ERROR(unable to locate gnome-config)
 else
   HTML_CFLAGS=`$GNOME_CONFIG  --cflags $module_args`
-  if test "x$?" == "x1"; then
+  if test "x$?" = "x1"; then
 	AC_MSG_ERROR(gnome-config doesn't seem to have support for gtkhtml)
   fi
   HTML_LIBS=`$GNOME_CONFIG  --libs $module_args`
