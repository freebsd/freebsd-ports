--- tools/qvfb/qanimationwriter.cpp.orig	Wed Nov 27 02:45:38 2002
+++ tools/qvfb/qanimationwriter.cpp	Wed Nov 27 02:45:56 2002
@@ -25,6 +25,7 @@
 
 #include <png.h>
 #include <netinet/in.h> // for htonl
+#include <limits.h>
 
 class QAnimationWriterData {
 public:
