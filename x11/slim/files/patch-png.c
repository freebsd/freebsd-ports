--- png.c.orig	2010-07-08 07:04:10.000000000 +0200
+++ png.c	2012-05-06 10:02:42.000000000 +0200
@@ -57,7 +57,7 @@
         return(0);
     }
   
-    if (setjmp(png_ptr->jmpbuf))
+    if (setjmp(png_jmpbuf(png_ptr)))
     {
         png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp) NULL);
         fclose(infile);
