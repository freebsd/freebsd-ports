--- ./package/xterm.spec.orig	2014-07-13 17:29:11.000000000 +0200
+++ ./package/xterm.spec	2014-07-15 09:09:15.488621885 +0200
@@ -1,11 +1,11 @@
-# $XTermId: xterm.spec,v 1.74 2014/07/13 15:29:11 tom Exp $
+# $XTermId: xterm.spec,v 1.75 2014/07/14 23:36:58 tom Exp $
 Summary: X terminal emulator (development version)
 %global my_middle xterm
 %global my_suffix -dev
 %global fullname %{my_middle}%{my_suffix}
 %global my_class XTermDev
 Name: %{fullname}
-Version: 309
+Version: 310
 Release: 1
 License: X11
 Group: User Interface/X
