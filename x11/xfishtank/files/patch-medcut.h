--- medcut.h.orig	2013-08-09 11:59:28 UTC
+++ medcut.h
@@ -4,6 +4,6 @@
 };
 
 extern void MedianInit();
-extern void MedianCount();
-extern void MedianSplit();
-extern void ConvertColor();
+extern void MedianCount( unsigned char *data, int w, int h, struct colr_data *colrs);
+extern void MedianSplit(int end_cnt);
+extern void ConvertColor(int *rp, int *gp, int *bp);
