--- include/util.h.orig	2007-11-16 13:59:15 UTC
+++ include/util.h
@@ -37,9 +37,9 @@ char *str_nil(char *s);
 int utflcpy(char *to, const char *from, int l);
 uint strlcat(char *dst, const char *src, unsigned int siz);
 
-char *argv0;
-void *__p;
-int __i;
+extern char *argv0;
+extern void *__p;
+extern int __i;
 #undef ARGBEGIN
 #undef ARGEND
 #undef ARGF
