--- util/xgettext/xgettext.c.orig	Sat Oct  4 19:07:38 2003
+++ util/xgettext/xgettext.c	Sat Oct  4 19:09:10 2003
@@ -193,7 +193,7 @@
 	
 	switch (*cp) {
 
-	case NULL:
+	case 0:
             readstd++;
             break;
 
