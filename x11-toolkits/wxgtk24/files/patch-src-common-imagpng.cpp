--- src/common/imagpng.cpp.orig	2003-09-21 13:31:39.000000000 +0200
+++ src/common/imagpng.cpp	2012-05-06 07:07:48.000000000 +0200
@@ -30,6 +30,7 @@
 #include "wx/log.h"
 #include "wx/app.h"
 #include "png.h"
+#include "pngpriv.h"
 #include "wx/filefn.h"
 #include "wx/wfstream.h"
 #include "wx/intl.h"
@@ -127,7 +128,7 @@
 #ifdef USE_FAR_KEYWORD
     {
        jmp_buf jmpbuf;
-       png_memcpy(jmpbuf,info->jmpbuf,sizeof(jmp_buf));
+       png_memcpy(jmpbuf,png_jmpbuf(info),sizeof(jmp_buf));
        longjmp(jmpbuf, 1);
     }
 #else
@@ -167,13 +168,13 @@
     image->Destroy();
 
     png_structp png_ptr = png_create_read_struct( PNG_LIBPNG_VER_STRING,
-        (voidp) NULL,
+        NULL,
         (png_error_ptr) NULL,
         (png_error_ptr) NULL );
     if (!png_ptr)
         goto error_nolines;
 
-    png_set_error_fn(png_ptr, (png_voidp)NULL, wx_png_error, wx_png_warning);
+    png_set_error_fn(png_ptr, NULL, wx_png_error, wx_png_warning);
 
     // NB: please see the comment near wxPNGInfoStruct declaration for
     //     explanation why this line is mandatory
@@ -349,7 +350,7 @@
         return FALSE;
     }
 
-    png_set_error_fn(png_ptr, (png_voidp)NULL, wx_png_error, wx_png_warning);
+    png_set_error_fn(png_ptr, NULL, wx_png_error, wx_png_warning);
 
     png_infop info_ptr = png_create_info_struct(png_ptr);
     if (info_ptr == NULL)
