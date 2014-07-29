--- src/init.c.orig	Wed Dec  4 03:21:17 2002
+++ src/init.c	Mon Oct 10 00:30:31 2005
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
@@ -1650,6 +1653,9 @@
     FOO(VEOL, "VEOL");
 # ifdef VEOL2
     FOO(VEOL2, "VEOL2");
+# endif
+# ifdef VERASE2
+    FOO(VERASE2, "VERASE2");
 # endif
 # ifdef VSWTC
     FOO(VSWTC, "VSWTC");
