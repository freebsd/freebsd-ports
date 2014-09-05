--- ./util/rrsocket.cpp.orig	2011-12-22 18:27:13.000000000 +0000
+++ ./util/rrsocket.cpp	2014-08-10 17:43:04.000000000 +0100
@@ -120,7 +120,7 @@
 #endif // USESSL
 
 
-rrsocket::rrsocket(bool dossl=false)
+rrsocket::rrsocket(bool dossl)
 	#ifdef USESSL
 	: _dossl(dossl)
 	#endif
