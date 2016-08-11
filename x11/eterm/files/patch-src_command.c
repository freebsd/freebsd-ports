--- src/command.c.orig	2011-03-16 06:05:03 UTC
+++ src/command.c
@@ -1561,7 +1561,7 @@ get_tty(void)
      * child processes remain alive upon deletion of the window.
      */
     {
-        unsigned short i;
+        unsigned long i;
         unsigned long max_fds;
 
         /* get number of available file descriptors */
