--- Manager.C.orig	1997-03-21 11:12:30 UTC
+++ Manager.C
@@ -368,7 +368,7 @@ Time WindowManager::timestamp(Boolean re
     return m_currentTime;
 }
 
-void WindowManager::sigHandler()
+void WindowManager::sigHandler(int)
 {
     m_signalled = True;
 }
