--- src/xdefaults.c.orig	Wed Dec  5 15:13:01 2001
+++ src/xdefaults.c	Wed Dec  5 15:15:37 2001
@@ -278,7 +278,9 @@
 #endif
     RSTRG(Rs_selectstyle, "selectstyle", "mode"),
     RSTRG(Rs_scrollstyle, "scrollstyle", "mode"),
+#ifdef HAVE_SCROLLBARS
     RSTRG(Rs_scrollBar_align, "scrollBar_align", "mode"),
+#endif
 #ifdef PRINTPIPE
     RSTRG(Rs_print_pipe, "print-pipe", "string"),
 #endif
