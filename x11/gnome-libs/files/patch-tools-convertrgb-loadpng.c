--- tools/convertrgb/loadpng.c.orig	1998-09-25 17:33:59.000000000 +0200
+++ tools/convertrgb/loadpng.c	2010-03-29 09:05:19.000000000 +0200
@@ -161,7 +161,7 @@
       return 0;
    fread(buf, 1, 8, f);
    fclose(f);
-   return (int)png_check_sig(buf, 8);
+   return (int)!png_sig_cmp(buf, 0, 8);
 #else
    return 0;
 #endif
