--- kitty/data-types.c.orig	2022-11-07 10:06:42 UTC
+++ kitty/data-types.c
@@ -40,14 +40,14 @@
 #include <xlocale.h>
 
 static PyObject*
-user_cache_dir() {
+user_cache_dir(void) {
     static char buf[1024];
     if (!confstr(_CS_DARWIN_USER_CACHE_DIR, buf, sizeof(buf) - 1)) return PyErr_SetFromErrno(PyExc_OSError);
     return PyUnicode_FromString(buf);
 }
 
 static PyObject*
-process_group_map() {
+process_group_map(void) {
     int num_of_processes = proc_listallpids(NULL, 0);
     size_t bufsize = sizeof(pid_t) * (num_of_processes + 1024);
     FREE_AFTER_FUNCTION pid_t *buf = malloc(bufsize);
