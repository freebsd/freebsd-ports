--- src/rxvtfont.C.orig	Wed Sep  8 13:44:38 2004
+++ src/rxvtfont.C	Sun Oct  3 03:07:41 2004
@@ -345,7 +345,7 @@
           uint32_t *a = linedraw_command + (offs >> 4);
           uint32_t *b = a + (offs & 15);
 
-          int W = r->TermWin.fwidth;
+          int W = r->TermWin.fwidth * wcwidth(t);
           int H = r->TermWin.fheight;
 
           int x_[16];
