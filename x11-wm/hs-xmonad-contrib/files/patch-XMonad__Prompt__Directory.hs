--- ./XMonad/Prompt/Directory.hs.orig	2011-08-21 14:07:27.601179305 +0300
+++ ./XMonad/Prompt/Directory.hs	2011-08-21 14:08:20.213520774 +0300
@@ -35,7 +35,7 @@
 
 getDirCompl :: String -> IO [String]
 getDirCompl s = (filter notboring . lines) `fmap`
-                runProcessWithInput "/bin/bash" [] ("compgen -A directory " ++ s ++ "\n")
+                runProcessWithInput "bash" [] ("compgen -A directory " ++ s ++ "\n")
 
 notboring :: String -> Bool
 notboring ('.':'.':_) = True
