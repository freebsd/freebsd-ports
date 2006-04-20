--- src/ylocale.cc.orig	Mon Apr 17 01:12:31 2006
+++ src/ylocale.cc	Mon Apr 17 16:19:46 2006
@@ -149,10 +149,11 @@
         return NULL;
 
     YUChar * uStr(new YUChar[lLen + 1]);
-    char * inbuf((char *) lStr), * outbuf((char *) uStr);
+    const char * inbuf((char *) lStr);
+    char * outbuf((char *) uStr);
     size_t inlen(lLen), outlen(4 * lLen);
 
-    if (0 > (int) iconv(instance->toUnicode, const_cast<char **>(&inbuf), &inlen, &outbuf, &outlen))
+    if (0 > (int) iconv(instance->toUnicode, &inbuf, &inlen, &outbuf, &outlen))
         warn(_("Invalid multibyte string \"%s\": %s"), lStr, strerror(errno));
 
     *((YUChar *) outbuf) = 0;
