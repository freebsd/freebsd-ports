--- src/command.c.orig	Thu Apr  5 03:52:39 2001
+++ src/command.c	Fri Jun 22 13:36:57 2001
@@ -2878,7 +2878,7 @@
     unsigned char   buf[256];
 
     va_start(arg_ptr, fmt);
-    vsprintf((char *)buf, fmt, arg_ptr);
+    vsnprintf((char *)buf, sizeof(buf), fmt, arg_ptr);
     va_end(arg_ptr);
     rxvt_tt_write(r, buf, (unsigned int)STRLEN(buf));
 }
