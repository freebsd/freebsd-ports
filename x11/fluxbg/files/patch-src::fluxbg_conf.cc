--- src/fluxbg_conf.cc.orig	Sat Aug  9 12:00:29 2003
+++ src/fluxbg_conf.cc	Tue Sep 30 20:53:24 2003
@@ -10,6 +10,8 @@
 #include <iostream>
 #include <fstream>
 #include <stdlib.h>
+#include <errno.h>
+#include <string.h>
 
 
 extern "C"{
@@ -158,6 +160,16 @@
 	BailOut();
 
 if (try_access("/usr/local/bin/fbsetbg")==1)
+	BailOut();
+
+/* FreeBSD installs stuff in a Better Place [tm]
+   also, the fluxbox-devel port appends "-devel" to binary names */
+
+if (try_access("%%X11BASE%%/bin/fbsetbg-devel")==1)
+	BailOut();
+if (try_access("%%X11BASE%%/bin/fbsetbg")==1)
+	BailOut();
+if (try_access("%%X11BASE%%/bin/bsetbg")==1)
 	BailOut();
 
 if (write_empty_conf()!=1)
