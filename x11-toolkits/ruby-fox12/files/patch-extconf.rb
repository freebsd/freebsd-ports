--- ext/fox/extconf.rb.orig	Fri Mar 22 08:00:40 2002
+++ ext/fox/extconf.rb	Fri Mar 22 12:13:55 2002
@@ -129,7 +129,7 @@
   find_library("GL", "glXCreateContext", "/usr/X11R6/lib")
   find_library("GLU", "gluNewQuadric", "/usr/X11R6/lib")
   $libs = append_library($libs, "FOX")
-  $CFLAGS = $CFLAGS + "-O0 -Iinclude"
+  $CFLAGS = $CFLAGS + "-O0 -Iinclude -fno-strict-prototype -fpermissive"
   if is_scintilla_build?
     File.move('scintilla_wrap.cpp.bak', 'scintilla_wrap.cpp') if FileTest.exists?('scintilla_wrap.cpp.bak')
     $CFLAGS = $CFLAGS + " -DWITH_FXSCINTILLA"
