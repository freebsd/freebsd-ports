--- PNG/Makefile.PL.orig	2010-01-12 08:23:36.000000000 -0500
+++ PNG/Makefile.PL	2010-01-12 08:26:18.000000000 -0500
@@ -16,7 +16,7 @@
  }
 
 if ($Tk::MMtry::VERSION ge '4.007' &&
-    try_run("config/has_png.c",['-I/usr/local/include'],['-lpng -lz -lm']))
+    try_run("config/has_png.c",['-I%%LOCALBASE%%/include'],['-L%%LOCALBASE%%/lib -lpng -lz -lm']))
  {
   Tk::MMutil::TkExtMakefile(
        NAME         => 'Tk::PNG',
@@ -24,8 +24,8 @@
        XS_VERSION   => $Tk::Config::VERSION,
        dist         => { COMPRESS => 'gzip -f9', SUFFIX => '.gz' },
        OBJECT       => '$(O_FILES)',
-       INC          => '-I/usr/local/include',
-       LIBS         => ['-lpng -lz -lm'],
+       INC          => '-I%%LOCALBASE%%/include',
+       LIBS         => ['-L%%LOCALBASE%%/lib -lpng -lz -lm'],
      );
  }
 else
