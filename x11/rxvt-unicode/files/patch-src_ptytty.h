--- src/ptytty.h
+++ src/ptytty.h
@@ -16,7 +16,7 @@
 #endif
 
 #if UTMP_SUPPORT
-# if !defined(UTMPX_FILE) || !defined(HAVE_STRUCT_UTMPX) || defined(__GLIBC__)
+# if !defined(HAVE_STRUCT_UTMPX) || defined(__GLIBC__)
 #  undef HAVE_UTMPX_H
 #  undef HAVE_STRUCT_UTMPX
 # endif
