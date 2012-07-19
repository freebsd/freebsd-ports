--- image.cpp.orig	2012-07-05 11:54:10.000000000 +0400
+++ image.cpp	2012-07-05 12:20:08.000000000 +0400
@@ -746,6 +746,10 @@
     return(ret);
 }
 
+#if (PNG_LIBPNG_VER_MAJOR == 1 && PNG_LIBPNG_VER_MINOR >= 5) || PNG_LIBPNG_VER_MAJOR > 1
+#define PNG_NEW_SETJMP_API
+#endif
+
 int
 Image::readPng(const char *filename, int *width, int *height,
                unsigned char **rgb, unsigned char **alpha)
@@ -781,7 +785,13 @@
                                 (png_infopp) NULL);
     }
 
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(
+#ifdef PNG_NEW_SETJMP_API
+(png_jmpbuf(png_ptr))
+#else
+png_ptr->jmpbuf
+#endif
+    )) {
         goto png_destroy;
     }
 
@@ -894,3 +904,4 @@
     fclose(infile);
     return(ret);
 }
+#undef PNG_NEW_SETJMP_API
