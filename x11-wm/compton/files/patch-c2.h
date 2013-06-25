--- src/c2.h.orig	2013-02-06 01:40:34.000000000 +0800
+++ src/c2.h	2013-02-06 01:40:53.000000000 +0800
@@ -35,10 +35,8 @@
 /// Pointer to a condition tree.
 typedef struct {
   bool isbranch : 1;
-  union {
-    c2_b_t *b;
-    c2_l_t *l;
-  };
+  c2_b_t *b;
+  c2_l_t *l;
 } c2_ptr_t;
 
 /// Initializer for c2_ptr_t.
