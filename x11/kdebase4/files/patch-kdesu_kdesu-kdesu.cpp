--- kdesu/kdesu/kdesu.cpp	2006/04/12 13:14:22	529044
+++ kdesu/kdesu/kdesu.cpp	2007/11/13 15:10:52	736127
@@ -113,7 +113,10 @@
     unsetenv( "SESSION_MANAGER" );
     KApplication app;
     // but propagate it to the started app
-    setenv( "SESSION_MANAGER", session_manager.data(), 1 );
+    if (session_manager.data())
+    {
+        setenv( "SESSION_MANAGER", session_manager.data(), 1 );
+    }
     
     {
         KStartupInfoId id;
