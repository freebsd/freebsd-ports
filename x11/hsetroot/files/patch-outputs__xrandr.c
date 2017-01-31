--- outputs_xrandr.c.orig	2016-02-14 00:09:11 UTC
+++ outputs_xrandr.c
@@ -31,7 +31,8 @@ OutputInfo
     close(pipefd[0]);
     dup2(pipefd[1], STDOUT_FILENO);
 
-    system("xrandr | grep ' connected' | sed -e 's/^.*\\s\\+\\([0-9]\\+x[0-9]\\+[-+][0-9]\\+[-+][0-9]\\+\\)\\s\\+.*$/\\1/'");
+    //system("xrandr | grep ' connected' | gsed -e 's/^.*\\s\\+\\([0-9]\\+x[0-9]\\+[-+][0-9]\\+[-+][0-9]\\+\\)\\s\\+.*$/\\1/'");
+    system("xrandr | grep ' connected' | sed -E -e 's/^.*[[:blank:]]+([0-9]+x[0-9]+[-+][0-9]+[-+][0-9]+)[[:blank:]]+.*$/\\1/'");
 
     close(pipefd[1]);
     _exit(0);
