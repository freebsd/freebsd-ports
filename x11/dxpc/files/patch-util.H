--- util.H.orig	Sun Aug 25 10:20:39 2002
+++ util.H	Sun Aug 25 10:23:01 2002
@@ -2,6 +2,7 @@
 #define util_H
 
 #include <fstream.h>
+#include <ostream.h>
 
 extern unsigned int GetUINT(unsigned const char *, int bigEndian);
 extern unsigned int GetULONG(unsigned const char *, int bigEndian);
