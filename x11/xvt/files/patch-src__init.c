--- src/init.c.orig	2014-12-09 12:50:59.000000000 -0800
+++ src/init.c	2014-12-09 12:54:55.000000000 -0800
@@ -1531,6 +1531,9 @@
 # ifdef VEOL2
     tio->c_cc[VEOL2] = VDISABLE;
 # endif
+# ifdef VERASE2
+    tio->c_cc[VERASE2] = CERASE2;
+# endif
 # ifdef VSWTC
     tio->c_cc[VSWTC] = VDISABLE;
 # endif
@@ -1651,6 +1654,9 @@
 # ifdef VEOL2
     FOO(VEOL2, "VEOL2");
 # endif
+# ifdef VERASE2
+    FOO(VERASE2, "VERASE2");
+# endif
 # ifdef VSWTC
     FOO(VSWTC, "VSWTC");
 # endif
