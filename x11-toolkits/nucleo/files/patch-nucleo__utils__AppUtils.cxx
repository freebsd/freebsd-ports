--- ./nucleo/utils/AppUtils.cxx.orig	2008-06-09 14:09:05.000000000 +0200
+++ ./nucleo/utils/AppUtils.cxx	2013-09-06 23:13:03.857491952 +0200
@@ -20,6 +20,7 @@
 #include <stdexcept>
 #include <cstdlib>
 #include <cstring>
+#include <unistd.h>
 
 extern char* optarg ;
 extern int optind ;
