--- src/ylocale.cc.orig	Wed Apr 21 05:06:34 2004
+++ src/ylocale.cc	Sun Apr 25 19:40:07 2004
@@ -149,7 +149,8 @@
 	return NULL;
 
     YUChar * uStr(new YUChar[lLen + 1]);
-    char * inbuf((char *) lStr), * outbuf((char *) uStr);
+    const char * inbuf((char *) lStr);
+    char * outbuf((char *) uStr);
     size_t inlen(lLen), outlen(4 * lLen);
 
     if (0 > (int) iconv(instance->toUnicode, &inbuf, &inlen, &outbuf, &outlen))
