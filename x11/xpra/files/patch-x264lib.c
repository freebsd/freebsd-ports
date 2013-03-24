--- xpra/x264/x264lib.c.orig	2013-03-24 18:53:16.000000000 +0000
+++ xpra/x264/x264lib.c	2013-03-24 19:29:09.000000000 +0000
@@ -7,6 +7,8 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <stdint.h>
+#include <inttypes.h>
 #include <string.h>
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -447,7 +449,7 @@
 		ctx->yuv2rgb = NULL;
 	}
         if (ctx->frame) {
-		avcodec_free_frame(&ctx->frame);
+		av_freep(&ctx->frame);
 		ctx->frame = NULL;
 	}
 }
