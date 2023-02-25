--- kitty/colors.c.orig	2022-11-07 10:06:42 UTC
+++ kitty/colors.c
@@ -47,7 +47,7 @@ init_FG_BG_table(void) {
     }
 }
 
-PyObject* create_256_color_table() {
+PyObject* create_256_color_table(void) {
     init_FG_BG_table();
     PyObject *ans = PyTuple_New(arraysz(FG_BG_256));
     if (ans == NULL) return PyErr_NoMemory();
@@ -83,7 +83,7 @@ dealloc_cp(ColorProfile* self) {
 }
 
 ColorProfile*
-alloc_color_profile() {
+alloc_color_profile(void) {
     return (ColorProfile*)new_cp(&ColorProfile_Type, NULL, NULL);
 }
 
