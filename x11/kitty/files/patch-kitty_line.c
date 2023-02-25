--- kitty/line.c.orig	2022-11-07 10:06:42 UTC
+++ kitty/line.c
@@ -944,7 +944,7 @@ PyTypeObject Line_Type = {
     .tp_new = new
 };
 
-Line *alloc_line() {
+Line *alloc_line(void) {
     Line *ans = (Line*)PyType_GenericAlloc(&Line_Type, 0);
     ans->needs_free = 0;
     return ans;
