
$FreeBSD$

--- src/generate.pl	2001/09/03 15:18:41	1.1
+++ src/generate.pl	2001/09/03 15:19:10
@@ -273,7 +273,7 @@
 $indent = $ENV{INDENT};
 $indent = "indent" unless $indent;
 
-readgtkheader "echo '#include <$modheader>'| cpp -P `gtk-config --cflags`|";
+readgtkheader "echo '#include <$modheader>'| cpp -P `gtk12-config --cflags`|";
 readmysource $source;
 
 open(OUT, "|$indent >realfuncs.h") ||die;
