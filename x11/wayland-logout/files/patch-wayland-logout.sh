lsof is slow and not supported on DragonFly

--- wayland-logout.sh.orig	2020-09-11 19:48:32 UTC
+++ wayland-logout.sh
@@ -1,7 +1,5 @@
 #!/bin/sh
 
-# REQUIREMENTS - lsof (not always present)
-
 if [ -z "${WAYLAND_DISPLAY}" ]; then
 	printf '%s\n' 'Error: WAYLAND_DISPLAY not set'
 	exit 1
@@ -21,7 +19,7 @@ case "${WAYLAND_DISPLAY}" in
 		;;
 esac
 
-WAYLAND_PIDS="$(lsof -t -f -- ${SOCKET_PATH})"
+WAYLAND_PIDS="$(sockstat -lu | awk "\$6 == \"${SOCKET_PATH}\" { print \$3 }" | uniq)"
 set -- $WAYLAND_PIDS
 if [ $# -gt 1 ]; then
 	printf '%s\n' 'Error: More than one process has been bound to the socket'
