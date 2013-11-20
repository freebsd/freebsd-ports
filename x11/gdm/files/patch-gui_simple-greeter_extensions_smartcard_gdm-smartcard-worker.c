--- gui/simple-greeter/extensions/smartcard/gdm-smartcard-worker.c.orig	2011-09-22 17:50:06.000000000 +0200
+++ gui/simple-greeter/extensions/smartcard/gdm-smartcard-worker.c	2011-09-22 17:51:09.000000000 +0200
@@ -2,7 +2,9 @@
 
 #include <fcntl.h>
 #include <locale.h>
+#ifdef __linux__
 #include <sys/prctl.h>
+#endif
 #include <stdlib.h>
 #include <unistd.h>
 
