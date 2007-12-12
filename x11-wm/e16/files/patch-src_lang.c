--- src/lang.c.orig	2007-10-06 15:16:39.000000000 +0800
+++ src/lang.c	2007-12-12 11:37:30.309489868 +0800
@@ -53,10 +53,11 @@
 Eiconv(iconv_t icd, const char *txt, size_t len)
 {
    char                buf[4096];
-   char               *pi, *po;
+   const char         *pi;
+   char               *po;
    size_t              err, ni, no;
 
-   pi = (char *)txt;
+   pi = txt;
    po = buf;
    ni = (len > 0) ? len : strlen(txt);
    if (!icd)
@@ -202,11 +203,12 @@
 EwcStrToWcs(const char *str, int len, wchar_t * wcs, int wcl)
 {
 #if HAVE_ICONV
-   char               *pi, *po;
+   const char         *pi;
+   char               *po;
    size_t              ni, no, rc;
    char                buf[4096];
 
-   pi = (char *)str;
+   pi = str;
    ni = len;
 
    if (!wcs)
@@ -242,10 +244,10 @@
 EwcWcsToStr(const wchar_t * wcs, int wcl, char *str, int len)
 {
 #if HAVE_ICONV
-   char               *pi;
+   const char         *pi;
    size_t              ni, no, rc;
 
-   pi = (char *)wcs;
+   pi = (const char *)wcs;
    ni = wcl * sizeof(wchar_t);
    no = len;
    rc = iconv(iconv_cd_wcs2str, &pi, &ni, &str, &no);
