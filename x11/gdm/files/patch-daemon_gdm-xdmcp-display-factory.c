--- daemon/gdm-xdmcp-display-factory.c.orig	2014-03-21 08:21:57.405582553 +0000
+++ daemon/gdm-xdmcp-display-factory.c	2014-03-21 08:22:13.029582593 +0000
@@ -77,7 +77,7 @@
 #define DEFAULT_USE_MULTICAST         FALSE
 #define DEFAULT_MULTICAST_ADDRESS     "ff02::1"
 #define DEFAULT_HONOR_INDIRECT        TRUE
-#define DEFAULT_MAX_DISPLAYS_PER_HOST 1
+#define DEFAULT_MAX_DISPLAYS_PER_HOST 2
 #define DEFAULT_MAX_DISPLAYS          16
 #define DEFAULT_MAX_PENDING_DISPLAYS  4
 #define DEFAULT_MAX_WAIT              30
