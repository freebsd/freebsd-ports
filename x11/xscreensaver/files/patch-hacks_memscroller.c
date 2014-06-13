--- hacks/memscroller.c.orig	2014-06-12 20:55:52.000000000 +0200
+++ hacks/memscroller.c	2014-06-12 20:56:03.000000000 +0200
@@ -349,9 +349,6 @@
          from earlier days before the advent of virtual memory management."
             -- sbrk(2) man page on MacOS
        */
-#  if (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 2)) /* gcc >= 4.2 */
-#   pragma GCC diagnostic ignored "-Wdeprecated-declarations"
-#  endif
       himem = ((unsigned char *) sbrk(0)) - (2 * sizeof(void *));
 # endif
 
