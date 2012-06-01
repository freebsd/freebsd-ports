--- tools/convertrgb/loadpng.c.orig	1998-09-25 17:33:59.000000000 +0200
+++ tools/convertrgb/loadpng.c	2012-05-09 13:02:52.000000000 +0200
@@ -3,6 +3,7 @@
  */
 
 #include "convertrgb.h"
+#include "pngpriv.h"
 
 static int transp;
 
@@ -29,7 +30,7 @@
 	return NULL;
      }
 
-   if (setjmp(png_ptr->jmpbuf))
+   if (setjmp(png_jmpbuf(png_ptr)))
      {
 	png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
 	return NULL;
@@ -161,7 +162,7 @@
       return 0;
    fread(buf, 1, 8, f);
    fclose(f);
-   return (int)png_check_sig(buf, 8);
+   return (int)!png_sig_cmp(buf, 0, 8);
 #else
    return 0;
 #endif
