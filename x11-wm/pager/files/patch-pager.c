--- pager.c.orig	Thu Nov 21 12:46:28 2002
+++ pager.c	Thu Nov 21 12:46:48 2002
@@ -24,6 +24,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <unistd.h>
+#include <sys/time.h>
 #include <sys/select.h>
 #include <gtk/gtk.h>
 
