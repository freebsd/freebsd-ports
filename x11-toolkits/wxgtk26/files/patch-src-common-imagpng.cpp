--- src/common/imagpng.cpp.orig	2007-03-20 16:50:01.000000000 +0100
+++ src/common/imagpng.cpp	2012-05-06 07:15:11.000000000 +0200
@@ -528,7 +528,7 @@
     png_structp png_ptr = png_create_read_struct
                           (
                             PNG_LIBPNG_VER_STRING,
-                            (voidp) NULL,
+                            NULL,
                             wx_png_error,
                             wx_png_warning
                           );
