--- src/command.c.orig
+++ src/command.c
@@ -1561,7 +1561,7 @@
      * child processes remain alive upon deletion of the window.
      */
     {
-        unsigned short i;
+        unsigned long i;
         unsigned long max_fds;
 
         /* get number of available file descriptors */
