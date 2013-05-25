--- src/XF86DGA2.c.orig	2013-03-25 20:23:42.796859881 +0100
+++ src/XF86DGA2.c	2013-03-25 20:23:17.997856725 +0100
@@ -21,6 +21,8 @@
 #include <X11/extensions/extutil.h>
 #include <stdio.h>
 
+#include <stdint.h>
+
 
 /* If you change this, change the Bases[] array below as well */
 #define MAX_HEADS 16
@@ -928,7 +930,7 @@
     if ((pMap->fd = open(name, O_RDWR)) < 0)
 	return False;
     pMap->virtual = mmap(NULL, size, PROT_READ | PROT_WRITE,
-			MAP_FILE | MAP_SHARED, pMap->fd, (off_t)base);
+			MAP_FILE | MAP_SHARED, pMap->fd, (off_t)(uintptr_t)base);
     if (pMap->virtual == (void *)-1)
 	return False;
     mprotect(pMap->virtual, size, PROT_READ | PROT_WRITE);
