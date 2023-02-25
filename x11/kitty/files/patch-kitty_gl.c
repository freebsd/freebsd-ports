--- kitty/gl.c.orig	2022-11-07 10:06:42 UTC
+++ kitty/gl.c
@@ -39,7 +39,7 @@ check_for_gl_error(void UNUSED *ret, const char *name,
 }
 
 void
-gl_init() {
+gl_init(void) {
     static bool glad_loaded = false;
     if (!glad_loaded) {
         int gl_version = gladLoadGL(glfwGetProcAddress);
