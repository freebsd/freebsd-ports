--- libgnomeui/gnome_segv.c.orig	Sun Oct 13 20:35:01 2002
+++ libgnomeui/gnome_segv.c	Sun Oct 13 20:39:29 2002
@@ -3,9 +3,9 @@
 
 /* needed for sigaction and friends under 'gcc -ansi -pedantic' on 
  * GNU/Linux */
-#ifndef _POSIX_SOURCE
+/*#ifndef _POSIX_SOURCE
 #  define _POSIX_SOURCE 1
-#endif
+#endif*/
 #include <sys/types.h>
 #include <sys/wait.h>
 
