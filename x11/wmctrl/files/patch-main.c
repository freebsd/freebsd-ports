--- main.c.orig	2005-01-29 03:31:33.000000000 +0000
+++ main.c	2010-12-20 11:09:11.000000000 +0000
@@ -1441,6 +1441,9 @@
 
     /* null terminate the result to make string handling easier */
     tmp_size = (ret_format / 8) * ret_nitems;
+    /* Correct 64 Architecture implementation of 32 bit data */
+    if (ret_format == 32)
+        tmp_size *= sizeof(long)/4;
     ret = g_malloc(tmp_size + 1);
     memcpy(ret, ret_prop, tmp_size);
     ret[tmp_size] = '\0';
