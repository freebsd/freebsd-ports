--- kitty/cursor.c.orig	2022-11-07 10:06:42 UTC
+++ kitty/cursor.c
@@ -321,7 +321,7 @@ copy(Cursor *self, PyObject *a UNUSED) {
     return (PyObject*)cursor_copy(self);
 }
 
-Cursor *alloc_cursor() {
+Cursor *alloc_cursor(void) {
     return (Cursor*)new(&Cursor_Type, NULL, NULL);
 }
 
