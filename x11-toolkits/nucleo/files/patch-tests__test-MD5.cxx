--- ./tests/test-MD5.cxx.orig	2008-06-05 14:52:33.000000000 +0200
+++ ./tests/test-MD5.cxx	2013-09-06 23:19:05.863746755 +0200
@@ -10,6 +10,7 @@
  */
 
 #include <nucleo/utils/MD5.H>
+#include <unistd.h>
 
 #include <iostream>
 
