--- rsibreak/src/rsitimer.cpp.orig	Thu Apr 20 21:48:42 2006
+++ rsibreak/src/rsitimer.cpp	Thu Apr 20 21:49:14 2006
@@ -62,7 +62,7 @@ RSITimer::RSITimer( QObject *parent, con
 #endif
 
     kdDebug() << "IDLE Detection is "
-              << (m_idleDetection?QString::null:"not")
+              << (m_idleDetection?QString::null:QString("not"))
               << "possible" << endl;
 
 
