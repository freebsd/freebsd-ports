--- src/ycmdline.cc.orig	Sun May 23 15:18:19 2004
+++ src/ycmdline.cc	Wed Aug  4 23:25:42 2004
@@ -55,7 +55,7 @@
 	if (*vptr == '=') ++vptr;
         while (ASCII::isSpaceOrTab(*vptr)) ++vptr;
     } else { // ------------------------- value assumed in the next argument ---
-	int idx(&arg - argv + 1);
+	int idx = &arg - static_cast<char const* const*>(argv) + 1;
 
 	if (idx < argc) {
 	    vptr = argv[idx];
