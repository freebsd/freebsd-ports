--- src/gtkcompletionline.cc	Thu Dec 18 14:47:42 2003
+++ src/gtkcompletionline.cc.orig	Thu Dec 18 14:50:30 2003
@@ -348,7 +348,7 @@
 }
 
 static int
-select_executables_only(const struct dirent* dent)
+select_executables_only(struct dirent* dent)
 {
   int len = strlen(dent->d_name);
   int lenp = prefix.length();
