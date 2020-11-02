--- include/util.h.orig	2010-06-10 07:24:03 UTC
+++ include/util.h
@@ -4,6 +4,10 @@
 #define nil	((void*)0)
 #define nelem(ary) (sizeof(ary) / sizeof(*ary))
 
+#ifndef EXTERN
+#   define EXTERN extern
+#endif
+
 /* Types */
 #undef uchar
 #undef ushort
@@ -55,7 +59,7 @@ char*	vsxprint(const char*, va_list);
 #define die(...) \
 	_die(__FILE__, __LINE__, __VA_ARGS__)
 
-char *argv0;
+EXTERN char *argv0;
 #undef ARGBEGIN
 #undef ARGEND
 #undef ARGF
