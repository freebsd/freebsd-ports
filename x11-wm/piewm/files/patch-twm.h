--- twm.h.orig	1998-06-03 08:42:52.000000000 -0700
+++ twm.h	2013-06-01 08:23:26.000000000 -0700
@@ -305,6 +305,12 @@
 #define TBPM_MENU ":menu"	/* name of titlebar pixmap for menus */
 #define TBPM_QUESTION ":question"	/* name of unknown titlebar pixmap */
 
+#ifndef X_NOT_STDC_ENV
+#include <stdlib.h>
+#else
+extern char *malloc(), *calloc(), *realloc(), *getenv();
+extern int free();
+#endif
 extern void Reborder(), Done();
 void ComputeCommonTitleOffsets();
 void ComputeWindowTitleOffsets(), ComputeTitleLocation();
