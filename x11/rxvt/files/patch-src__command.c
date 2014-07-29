--- src/command.c.orig	Thu Nov  1 22:18:35 2001
+++ src/command.c	Mon Oct 10 00:29:07 2005
@@ -254,7 +254,7 @@
 	extern char    *ptsname();
 
 #  ifdef PTYS_ARE_GETPT
-	if ((fd = getpt()) >= 0) {
+	if ((fd = posix_openpt(O_RDWR)) >= 0) {
 #  else
 	if ((fd = open("/dev/ptmx", O_RDWR)) >= 0) {
 #  endif
@@ -519,6 +519,9 @@
 # ifdef VEOL2
     FOO(VEOL2, "VEOL2");
 # endif
+# ifdef VERASE2
+    FOO(VERASE2, "VERASE2");
+# endif
 # ifdef VSWTC
     FOO(VSWTC, "VSWTC");
 # endif
@@ -596,6 +599,9 @@
 # ifdef VSWTCH
     tio->c_cc[VSWTCH] = VDISABLE;
 # endif
+# ifdef VERASE2
+    tio->c_cc[VERASE2] = CERASE2;
+# endif
 # if VMIN != VEOF
     tio->c_cc[VMIN] = 1;
 # endif
@@ -2376,7 +2382,7 @@
     unsigned char   buf[256];
 
     va_start(arg_ptr, fmt);
-    vsprintf(buf, fmt, arg_ptr);
+    vsnprintf(buf, sizeof(buf), fmt, arg_ptr);
     va_end(arg_ptr);
     tt_write(buf, strlen(buf));
 }
