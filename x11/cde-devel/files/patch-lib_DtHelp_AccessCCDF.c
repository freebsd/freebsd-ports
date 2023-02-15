--- lib/DtHelp/AccessCCDF.c.orig	2023-02-14 22:04:50.544937000 -0800
+++ lib/DtHelp/AccessCCDF.c	2023-02-14 22:21:52.663351000 -0800
@@ -59,6 +59,8 @@
 extern int errno;
 #endif
 
+extern char *_DtHelpGetLocale(void);
+
 /*
  * Canvas Engine includes
  */
