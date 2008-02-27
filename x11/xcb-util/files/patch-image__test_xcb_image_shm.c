--- ./image/test_xcb_image_shm.c.orig	2006-10-07 16:41:22.000000000 -0300
+++ ./image/test_xcb_image_shm.c	2008-02-26 23:14:44.000000000 -0300
@@ -1,6 +1,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 
+#include <sys/types.h>
 #include <sys/ipc.h>
 #include <sys/shm.h>
 
