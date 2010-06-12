--- ./src/preview_update.c.orig	2010-05-12 20:09:07.177608591 +0400
+++ ./src/preview_update.c	2010-05-12 20:09:21.638774481 +0400
@@ -1,4 +1,5 @@
 #include "preview_update.h"
+#include "preview.h"
 #include "main.h"
 
 static gboolean restart_theme_preview_update = TRUE;
