--- JPEG/Makefile.PL.orig	2010-01-12 08:28:55.000000000 -0500
+++ JPEG/Makefile.PL	2010-01-12 08:32:23.000000000 -0500
@@ -13,10 +13,10 @@
 
 use Tk::MMtry;
 
-if ($Tk::MMtry::VERSION ge '4.007' && try_run("jpeg/has_jpeg.c",['-I/usr/local/include'],['-ljpeg']))
+if ($Tk::MMtry::VERSION ge '4.007' && try_run("jpeg/has_jpeg.c",['-I%%LOCALBASE%%/include'],['-L%%LOCALBASE%%/lib -ljpeg']))
  {
-  push(@args, LIBS => ['-ljpeg'],
-              INC  => '-I/usr/local/include',
+  push(@args, LIBS => ['-L%%LOCALBASE%%/lib -ljpeg'],
+              INC  => '-I%%LOCALBASE%%/include',
               DEFINE => '-DHAVE_JPEGLIB_H',
       );
   warn "Using system's -ljpeg\n";
