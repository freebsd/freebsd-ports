--- build-aux/find-x-server.sh.orig	2023-05-05 18:12:53 UTC
+++ build-aux/find-x-server.sh
@@ -29,6 +29,10 @@ elif test -x /usr/openwin/bin/Xsun; then
     echo "/usr/openwin/bin/Xsun"
 elif test -x /opt/X11R6/bin/X; then
     echo "/opt/X11R6/bin/X"
+elif test -x /usr/local/bin/Xorg; then
+    echo "/usr/local/bin/Xorg"
+elif test -x /usr/local/bin/X; then
+    echo "/usr/local/bin/X"
 else
     echo ""
 fi
