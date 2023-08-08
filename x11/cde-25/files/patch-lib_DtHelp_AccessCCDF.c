--- lib/DtHelp/AccessCCDF.c.orig	2023-02-14 22:10:39.197575000 -0800
+++ lib/DtHelp/AccessCCDF.c	2023-02-14 22:19:30.922211000 -0800
@@ -59,6 +59,8 @@
 extern int errno;
 #endif
 
+extern char *_DtHelpGetLocale(void);
+
 /*
  * Canvas Engine includes
  */
