diff -u -r util/fbrun/FbRun.hh.orig util/fbrun/FbRun.hh
--- util/fbrun/FbRun.hh.orig Sat Dec  7 09:15:27 2002
+++ util/fbrun/FbRun.hh	Mon Oct 27 23:57:51 2003
@@ -29,6 +29,7 @@
 
 #include <string>
 #include <vector>
+#include <cassert>
 
 /**
 	Creates and managed a run window
