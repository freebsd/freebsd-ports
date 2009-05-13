--- src/helpers.cpp.orig	2009-05-13 16:55:33.000000000 +0200
+++ src/helpers.cpp	2009-05-13 16:57:42.000000000 +0200
@@ -1656,7 +1656,7 @@
         target = new wxString(tmpPtr, *wxConvCurrent, tmpSize);
     }
 #else
-    char* tmpPtr; int tmpSize;
+    char* tmpPtr; Py_ssize_t tmpSize;
     if (PyString_AsStringAndSize(source, &tmpPtr, &tmpSize) == -1) {
         PyErr_SetString(PyExc_TypeError, "Unable to convert string");
         return NULL;
@@ -1702,7 +1702,7 @@
         target = wxString(tmpPtr, *wxConvCurrent, tmpSize);
     }
 #else
-    char* tmpPtr; int tmpSize;
+    char* tmpPtr; Py_ssize_t tmpSize;
     PyString_AsStringAndSize(source, &tmpPtr, &tmpSize);
     target = wxString(tmpPtr, tmpSize);
 #endif // wxUSE_UNICODE
