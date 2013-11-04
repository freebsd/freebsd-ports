--- src/ylocale.cc.orig	2013-11-03 19:58:39.180727369 -0500
+++ src/ylocale.cc	2013-11-03 19:58:51.540725980 -0500
@@ -126,8 +126,12 @@ YLocale::~YLocale() {
 iconv_t YLocale::getConverter (const char *from, const char **&to) {
     iconv_t cd = (iconv_t) -1;
 
+    char *myfrom = (char *)malloc(1 + strlen(from));
+    strcpy(myfrom, from);
+    char *modptr = strstr(myfrom, "//");
+    if (NULL != modptr) *modptr = '\0';
     while (NULL != *to)
-        if ((iconv_t) -1 != (cd = iconv_open(*to, from))) return cd;
+        if ((iconv_t) -1 != (cd = iconv_open(*to, myfrom))) return cd;
         else ++to;
 
     return (iconv_t) -1;
@@ -149,7 +153,8 @@ YUChar *YLocale::unicodeString(const YLC
         return NULL;
 
     YUChar * uStr(new YUChar[lLen + 1]);
-    char * inbuf((char *) lStr), * outbuf((char *) uStr);
+    const char * inbuf((char *) lStr);
+    char * outbuf((char *) uStr);
     size_t inlen(lLen), outlen(4 * lLen);
 
     if (0 > (int) iconv(instance->toUnicode, &inbuf, &inlen, &outbuf, &outlen))
