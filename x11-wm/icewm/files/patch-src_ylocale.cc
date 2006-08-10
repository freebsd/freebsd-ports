--- src/ylocale.cc.orig	Mon Aug  7 03:38:14 2006
+++ src/ylocale.cc	Tue Aug  8 01:00:33 2006
@@ -149,7 +149,8 @@
         return NULL;
 
     YUChar * uStr(new YUChar[lLen + 1]);
-    char * inbuf((char *) lStr), * outbuf((char *) uStr);
+    const char * inbuf((char *) lStr);
+    char * outbuf((char *) uStr);
     size_t inlen(lLen), outlen(4 * lLen);
 
     if (0 > (int) iconv(instance->toUnicode, &inbuf, &inlen, &outbuf, &outlen))
