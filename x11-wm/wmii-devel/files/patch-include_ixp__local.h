--- include/ixp_local.h.orig	2020-10-18 08:53:49 UTC
+++ include/ixp_local.h
@@ -3,7 +3,11 @@
 #include <ixp.h>
 #include <stdbool.h>
 
-char *argv0;
+#ifndef EXTERN
+# define EXTERN extern
+#endif
+
+EXTERN char *argv0;
 #define ARGBEGIN \
 		int _argtmp=0, _inargv=0; char *_argv=nil; \
 		if(!argv0) {argv0=*argv; argv++, argc--;} \
