--- Manager.h.orig	1997-03-21 11:12:30 UTC
+++ Manager.h
@@ -85,7 +85,7 @@ private:
 
     static Boolean m_initialising;
     static int errorHandler(Display *, XErrorEvent *);
-    static void sigHandler();
+    static void sigHandler(int);
     static int m_signalled;
 
     void initialiseScreen();
