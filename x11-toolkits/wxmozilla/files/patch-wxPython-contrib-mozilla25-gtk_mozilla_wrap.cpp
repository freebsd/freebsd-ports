--- wxPython/contrib/mozilla25/gtk/mozilla_wrap.cpp.orig	2008-03-18 16:21:58.000000000 +0100
+++ wxPython/contrib/mozilla25/gtk/mozilla_wrap.cpp	2008-03-18 16:24:58.000000000 +0100
@@ -1228,7 +1228,7 @@
     obj = pyobj;
     if (PyCFunction_Check(obj)) {
       /* here we get the method pointer for callbacks */
-      char *doc = (((PyCFunctionObject *)obj) -> m_ml -> ml_doc);
+      const char *doc = (((PyCFunctionObject *)obj) -> m_ml -> ml_doc);
       c = doc ? strstr(doc, "swig_ptr: ") : 0;
       if (c) {
 	c = ty ? SWIG_UnpackVoidPtr(c + 10, &vptr, ty->name) : 0;
@@ -8120,11 +8120,11 @@
     swig_type_info **types_initial) {
         size_t i;
         for (i = 0; methods[i].ml_name; ++i) {
-            char *c = methods[i].ml_doc;
+            const char *c = methods[i].ml_doc;
             if (c && (c = strstr(c, "swig_ptr: "))) {
                 int j;
                 swig_const_info *ci = 0;
-                char *name = c + 10;
+                const char *name = c + 10;
                 for (j = 0; const_table[j].type; ++j) {
                     if (strncmp(const_table[j].name, name, 
                     strlen(const_table[j].name)) == 0) {
