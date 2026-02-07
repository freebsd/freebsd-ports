--- lib/ReadPacket.c.orig	1996-08-21 14:23:34 UTC
+++ lib/ReadPacket.c
@@ -9,7 +9,7 @@
  * unsigned long header[3];
  * unsigned long *body;
  * int fd[2];
- * void DeadPipe(int nonsense); /* Called if the pipe is no longer open 
+ * void DeadPipe(int nonsense); // Called if the pipe is no longer open 
  *
  * ReadASPacket(fd[1],header, &body);
  *
