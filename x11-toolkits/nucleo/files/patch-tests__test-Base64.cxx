--- ./tests/test-Base64.cxx.orig	2008-06-09 15:21:20.000000000 +0200
+++ ./tests/test-Base64.cxx	2013-09-06 23:18:36.765608410 +0200
@@ -11,6 +11,7 @@
 
 #include <nucleo/utils/AppUtils.H>
 #include <nucleo/utils/Base64.H>
+#include <unistd.h>
 
 #include <iostream>
 #include <cstdlib>
