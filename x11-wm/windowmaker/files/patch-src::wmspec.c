--- src/wmspec.c.orig	Sat Oct 23 12:18:47 2004
+++ src/wmspec.c	Sun Oct 24 02:57:37 2004
@@ -392,8 +392,8 @@
         RImage *new_rimage;
 
         do {
-            len = data[pos+0]*data[pos+1];
             unsigned int tmp = pref_sq-len;
+            len = data[pos+0]*data[pos+1];
             if (tmp < best_tmp && tmp > 0) {
                 best_tmp = tmp;
                 best_pos = pos;
