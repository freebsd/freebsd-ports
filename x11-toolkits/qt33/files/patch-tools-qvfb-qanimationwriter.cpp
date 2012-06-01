--- tools/qvfb/qanimationwriter.cpp.orig	2007-01-11 14:39:56.000000000 +0100
+++ tools/qvfb/qanimationwriter.cpp	2012-04-27 11:57:18.000000000 +0200
@@ -24,6 +24,7 @@
 #include <qfile.h>
 
 #include <png.h>
+#include <pngpriv.h>
 #include <netinet/in.h> // for htonl
 
 class QAnimationWriterData {
