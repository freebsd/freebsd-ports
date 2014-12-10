--- src/command.c.orig	2014-12-09 12:06:57.000000000 -0800
+++ src/command.c	2014-12-09 12:07:41.000000000 -0800
@@ -3098,7 +3098,7 @@
     unsigned char   buf[256];
 
     va_start(arg_ptr, fmt);
-    vsprintf((char *)buf, fmt, arg_ptr);
+    vsnprintf((char *)buf, sizeof(buf), fmt, arg_ptr);
     va_end(arg_ptr);
     xvt_tt_write(r, buf, (unsigned int)STRLEN(buf));
 }
