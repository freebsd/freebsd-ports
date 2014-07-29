--- Manager.C.orig	Fri Mar 21 12:12:30 1997
+++ Manager.C	Tue Jan 28 17:45:03 2003
@@ -368,7 +368,7 @@
     return m_currentTime;
 }
 
-void WindowManager::sigHandler()
+void WindowManager::sigHandler(int)
 {
     m_signalled = True;
 }
