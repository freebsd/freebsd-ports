--- src/Resources.cc.orig	Wed May 12 15:55:06 2004
+++ src/Resources.cc	Thu Mar  3 19:21:58 2005
@@ -171,7 +171,7 @@
 
     __render_thread_count = 0;
     
-    if (value_str) {
+    if (value_str)
       if (! strcasecmp("true", value_str))
         __render_thread_count = 1;      
 
