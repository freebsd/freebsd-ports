--- kdecore/kasyncio.cpp.orig	Sun Mar  3 16:21:58 2002
+++ kdecore/kasyncio.cpp	Tue Nov 19 07:23:30 2002
@@ -26,3 +26,5 @@
 void KAsyncIO::virtual_hook( int, void* )
 { /*BASE::virtual_hook( id, data );*/ }
 
+#include "kasyncio.moc"
+#include "kgenericfactory.moc"
