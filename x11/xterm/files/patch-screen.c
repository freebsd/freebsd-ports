--- screen.c.orig	2015-03-07 01:19:23 UTC
+++ screen.c
@@ -1,4 +1,4 @@
-/* $XTermId: screen.c,v 1.510 2015/03/07 01:19:23 tom Exp $ */
+/* $XTermId: screen.c,v 1.512 2015/03/22 14:47:02 tom Exp $ */
 
 /*
  * Copyright 1999-2014,2015 by Thomas E. Dickey
@@ -1248,7 +1248,7 @@ ScrnInsertChar(XtermWidget xw, unsigned 
 
     TScreen *screen = TScreenOf(xw);
     int first = ScrnLeftMargin(xw);
-    int last = ScrnRightMargin(xw) + 1;
+    int last = ScrnRightMargin(xw);
     int row = screen->cur_row;
     int col = screen->cur_col;
     int j;
@@ -1258,13 +1258,13 @@ ScrnInsertChar(XtermWidget xw, unsigned 
 	TRACE(("ScrnInsertChar - col %d outside [%d..%d]\n", col, first, last));
 	return;
     } else if (last < (col + (int) n)) {
-	n = (unsigned) (last - col);
+	n = (unsigned) (last + 1 - col);
     }
 
     assert(screen->cur_col >= 0);
     assert(screen->cur_row >= 0);
     assert((int) n >= 0);
-    assert(last >= (int) n);
+    assert((last + 1) >= (int) n);
 
     if_OPT_WIDE_CHARS(screen, {
 	int xx = screen->cur_row;
@@ -1273,7 +1273,7 @@ ScrnInsertChar(XtermWidget xw, unsigned 
 	if (DamagedCells(screen, n, &kl, (int *) 0, xx, kr) && kr > kl) {
 	    ClearCells(xw, 0, (unsigned) (kr - kl + 1), row, kl);
 	}
-	kr = last - (int) n;
+	kr = last - (int) n + 1;
 	if (DamagedCells(screen, n, &kl, (int *) 0, xx, kr) && kr > kl) {
 	    ClearCells(xw, 0, (unsigned) (kr - kl + 1), row, kl);
 	}
