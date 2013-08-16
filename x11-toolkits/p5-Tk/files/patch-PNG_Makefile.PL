--- PNG/Makefile.PL.orig	2013-05-21 06:25:13.000000000 -0700
+++ PNG/Makefile.PL	2013-08-16 13:56:20.750936409 -0700
@@ -23,8 +23,8 @@
     chomp($libpng_libs   = `pkg-config --libs libpng`);
 } else {
     warn "'pkg-config libpng' failed, continue with fallback values for cflags and libs...\n";
-    $libpng_cflags = '-I/usr/local/include';
-    $libpng_libs   = '-lpng -lz -lm';
+    $libpng_cflags = '-I%%LOCALBASE%%/include';
+    $libpng_libs   = '-L%%LOCALBASE%%/lib -lpng -lz -lm';
 }
 
 if ($Tk::MMtry::VERSION ge '4.007' &&
