--- ext/fox/extconf.rb.orig	Sun Jan 27 03:57:10 2002
+++ ext/fox/extconf.rb	Sun Jan 27 04:01:57 2002
@@ -120,7 +120,7 @@
   find_library("GL", "glXCreateContext", "/usr/X11R6/lib")
   find_library("GLU", "gluNewQuadric", "/usr/X11R6/lib")
   $libs = append_library($libs, "FOX")
-  $CFLAGS = $CFLAGS + "-O0 -DSWIG_NOINCLUDE -Iinclude"
+  $CFLAGS = $CFLAGS + "-DSWIG_NOINCLUDE -Iinclude -fno-strict-prototype -fpermissive"
   if isScintillaBuild
     $CFLAGS = $CFLAGS + " -DWITH_FXSCINTILLA"
     $libs = append_library($libs, "scintilla")
