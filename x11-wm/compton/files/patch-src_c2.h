--- src/c2.h.orig	2016-09-07 08:23:44 UTC
+++ src/c2.h
@@ -35,10 +35,8 @@ typedef struct _c2_l c2_l_t;
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
