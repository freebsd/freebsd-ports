--- src/command.c.orig	Thu Apr  5 03:52:39 2001
+++ src/command.c	Fri Jun 22 13:36:57 2001
@@ -2796,7 +2796,7 @@ rxvt_tt_printf(rxvt_t *r, const char *fm
     unsigned char   buf[256];
 
     va_start(arg_ptr, fmt);
-    vsprintf(buf, fmt, arg_ptr);
+    vsnprintf(buf, sizeof(buf), fmt, arg_ptr);
     va_end(arg_ptr);
     rxvt_tt_write(r, buf, STRLEN(buf));
 }
