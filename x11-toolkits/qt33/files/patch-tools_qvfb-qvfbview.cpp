--- tools/qvfb/qvfbview.cpp.orig	Wed Mar 21 08:48:22 2007
+++ tools/qvfb/qvfbview.cpp	Wed Mar 21 08:48:33 2007
@@ -115,7 +115,7 @@
 	data = (unsigned char *)shmat( shmId, 0, 0 );
     }
 
-    if ( (int)data == -1 )
+    if ( (long)data == -1 )
 	qFatal( "Cannot attach to shared memory" );
 
     hdr = (QVFbHeader *)data;
