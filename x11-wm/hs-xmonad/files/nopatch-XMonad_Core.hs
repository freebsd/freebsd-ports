--- XMonad/Core.hs.orig	2013-01-01 01:31:47 UTC
+++ XMonad/Core.hs
@@ -400,10 +400,13 @@ spawnPID x = xfork $ executeFile "/bin/s
 
 -- | A replacement for 'forkProcess' which resets default signal handlers.
 xfork :: MonadIO m => IO () -> m ProcessID
-xfork x = io . forkProcess . finally nullStdin $ do
-                uninstallSignalHandlers
-                createSession
-                x
+xfork x = do 
+    pid <- liftIO $ forkProcess $ finally nullStdin $ do
+        forkProcess $ do
+            uninstallSignalHandlers
+            createSession
+            x
+    return pid
  where
     nullStdin = do
         fd <- openFd "/dev/null" ReadOnly Nothing defaultFileFlags
