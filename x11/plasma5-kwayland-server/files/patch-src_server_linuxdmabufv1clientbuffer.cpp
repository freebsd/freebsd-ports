--- src/server/linuxdmabufv1clientbuffer.cpp.orig	2022-02-08 21:40:49 UTC
+++ src/server/linuxdmabufv1clientbuffer.cpp
@@ -17,6 +17,7 @@
 
 #include <QTemporaryFile>
 #include <fcntl.h>
+#include <errno.h>
 
 namespace KWaylandServer
 {
