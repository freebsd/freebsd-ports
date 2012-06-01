--- fvwm-insitu/libs/PictureImageLoader.c.orig	2008-12-09 13:52:20.000000000 +0100
+++ fvwm-insitu/libs/PictureImageLoader.c	2012-05-22 07:28:06.000000000 +0200
@@ -44,6 +44,7 @@
 #include "Fgdk-pixbuf.h"
 #include "FRenderInit.h"
 #include "FImage.h"
+#include "pngpriv.h"
 
 /* ---------------------------- local definitions -------------------------- */
 #define FIMAGE_CMD_ARGS Display *dpy, Window win, char *path, \
