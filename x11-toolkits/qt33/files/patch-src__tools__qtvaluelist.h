--- src/tools/qvaluelist.h.orig	2007-02-02 09:01:04.000000000 -0500
+++ src/tools/qvaluelist.h	2011-08-12 02:41:45.000000000 -0400
@@ -45,6 +45,7 @@
 #endif // QT_H
 
 #ifndef QT_NO_STL
+#include <cstddef>
 #include <iterator>
 #include <list>
 #endif
