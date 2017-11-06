--- startkde.cmake.orig	2015-06-26 03:17:21 UTC
+++ startkde.cmake
@@ -271,7 +271,8 @@ export XDG_DATA_DIRS
 # Make sure that D-Bus is running
 # D-Bus autolaunch is broken
 if test -z "$DBUS_SESSION_BUS_ADDRESS" ; then
-    eval `dbus-launch --sh-syntax --exit-with-session`
+    uuid="`dbus-uuidgen --get`"
+    eval `dbus-launch --sh-syntax --exit-with-session --autolaunch $uuid`
 fi
 if $qdbus >/dev/null 2>/dev/null; then
     : # ok
