--- startkde.cmake.orig	2009-10-07 08:37:24.000000000 +1100
+++ startkde.cmake	2009-12-28 10:02:07.133352180 +1000
@@ -337,7 +337,8 @@
 fi
 # D-Bus autolaunch is broken
 if test -z "$DBUS_SESSION_BUS_ADDRESS" ; then
-    eval `dbus-launch --sh-syntax --exit-with-session`
+    uuid="`dbus-uuidgen --get`"
+    eval `dbus-launch --sh-syntax --exit-with-session --autolaunch $uuid`
 fi
 if qdbus >/dev/null 2>/dev/null; then
     : # ok
