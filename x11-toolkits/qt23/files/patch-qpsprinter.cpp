--- src/kernel/qpsprinter.cpp.orig	Wed Jun 13 01:53:46 2001
+++ src/kernel/qpsprinter.cpp	Sun Feb  9 22:48:14 2003
@@ -2772,7 +2772,7 @@
 
 
 #ifndef _OS_OSF_
-extern "C" char* getenv(char*);
+extern "C" char* getenv(const char*);
 #endif
 
 QPSPrinterFontTTF::QPSPrinterFontTTF(const QFont &f, QByteArray& d)
