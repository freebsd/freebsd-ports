--- src/FbTk/Font.cc.orig	Mon Sep 20 12:45:01 2004
+++ src/FbTk/Font.cc	Fri Oct 15 18:04:48 2004
@@ -89,9 +89,7 @@
 
 namespace {
 
-#ifdef HAVE_SETLOCALE
 #include <locale.h>
-#endif //HAVE_SETLOCALE
 
 #ifdef HAVE_ICONV
 /**
