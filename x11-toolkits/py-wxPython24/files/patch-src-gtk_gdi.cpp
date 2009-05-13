--- src/gtk/gdi.cpp.orig	2003-09-23 01:06:27.000000000 +0200
+++ src/gtk/gdi.cpp	2009-05-13 17:59:41.000000000 +0200
@@ -137,7 +137,7 @@
 
     wxBitmap* wxBitmapFromBits(PyObject* bits, int width, int height, int depth = 1 ) {
         char* buf;
-        int   length;
+        Py_ssize_t length;
         PyString_AsStringAndSize(bits, &buf, &length);
         return new wxBitmap(buf, width, height, depth);
     }
@@ -193,7 +193,7 @@
                                PyObject* maskBits=0) {
         char* bitsbuf;
         char* maskbuf = NULL;
-        int   length;
+        Py_ssize_t length;
         PyString_AsStringAndSize(bits, &bitsbuf, &length);
         if (maskBits)
             PyString_AsStringAndSize(maskBits, &maskbuf, &length);
