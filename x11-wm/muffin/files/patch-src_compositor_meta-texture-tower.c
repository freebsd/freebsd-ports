--- src/compositor/meta-texture-tower.c.orig	2013-11-23 13:42:35.000000000 +0000
+++ src/compositor/meta-texture-tower.c	2014-03-31 08:00:34.767127023 +0000
@@ -365,13 +365,9 @@
         meta_texture_rectangle_new (width, height,
                                     /* data format */
                                     TEXTURE_FORMAT,
-                                    /* internal cogl format */
-                                    TEXTURE_FORMAT,
                                     /* rowstride */
                                     width * 4,
                                     /* data */
-                                    NULL,
-                                    /* error */
                                     NULL);
     }
   else
