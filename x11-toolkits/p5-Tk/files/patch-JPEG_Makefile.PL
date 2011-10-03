--- JPEG/Makefile.PL.orig	2010-06-01 03:58:38.000000000 +0800
+++ JPEG/Makefile.PL	2011-10-03 23:34:18.892396436 +0800
@@ -6,10 +6,10 @@
 
 use Tk::MMtry;
 
-if ($Tk::MMtry::VERSION ge '4.007' && try_run("config/has_jpeg.c",['-I/usr/local/include'],['-ljpeg']))
+if ($Tk::MMtry::VERSION ge '4.007' && try_run("config/has_jpeg.c",['-I%%LOCALBASE%%/include'],['-L%%LOCALBASE%%/lib -ljpeg']))
  {
-  push(@args, LIBS => ['-ljpeg'],
-              INC  => '-I/usr/local/include',
+  push(@args, LIBS => ['-L%%LOCALBASE%%/lib -ljpeg'],
+              INC  => '-I%%LOCALBASE%%/include',
               DEFINE => '-DHAVE_JPEGLIB_H',
       );
   warn "Using system's -ljpeg\n";
