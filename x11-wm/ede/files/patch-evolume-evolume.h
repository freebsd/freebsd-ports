--- evolume/evolume.h.orig	Wed Jul 20 11:38:26 2005
+++ evolume/evolume.h	Wed Jul 20 11:38:46 2005
@@ -13,7 +13,7 @@
 #include <string.h>
 #include <sys/errno.h>
 #include <fcntl.h>
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 #include <sys/ioctl.h>
 }
 
