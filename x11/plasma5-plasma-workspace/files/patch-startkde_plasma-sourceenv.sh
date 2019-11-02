--- startkde/plasma-sourceenv.sh.orig	2019-11-02 22:09:17 UTC
+++ startkde/plasma-sourceenv.sh
@@ -3,4 +3,4 @@ do
     . $i >/dev/null
 done
 
-env -0
+genv -0
