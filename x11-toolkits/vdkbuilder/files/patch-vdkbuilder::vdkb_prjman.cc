--- vdkbuilder/vdkb_prjman.cc.orig	Sat Feb  1 19:44:06 2003
+++ vdkbuilder/vdkb_prjman.cc	Mon Nov 17 14:40:01 2003
@@ -49,8 +49,8 @@
 #define N_(str) str 
 #endif
 #endif
-#undef __REGEXP_LIBRARY_H__
-#define __REGEXP_LIBRARY_H__ 1 // do not include builtin regex.h
+// #undef __REGEXP_LIBRARY_H__
+// #define __REGEXP_LIBRARY_H__ 1 // do not include builtin regex.h
 // STUB #include <vdkb2/vdkb_ccpane.h>
 #include <vdkb2/vdkb_prjman.h>
 #include <vdkb2/vdkb_locale.h>
