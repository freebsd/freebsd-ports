--- ../kpty/kptydevice.cpp.orig	2008-07-14 10:04:55.000000000 -0400
+++ ../kpty/kptydevice.cpp	2008-07-14 10:05:24.000000000 -0400
@@ -265,7 +265,8 @@
 #else
     int available;
 #endif
-    if (!::ioctl(q->masterFd(), FIONREAD, (char *) &available)) {
+    //if (!::ioctl(q->masterFd(), FIONREAD, (char *) &available)) {
+    if (!::ioctl(q->masterFd(), TIOCOUTQ, (char *) &available)) {
         char *ptr = readBuffer.reserve(available);
         NO_INTR(readBytes, read(q->masterFd(), ptr, available));
         if (readBytes < 0) {
