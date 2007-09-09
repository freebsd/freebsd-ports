Index: src/screen.c
===================================================================
--- src/screen.c	(revision 244)
+++ src/screen.c	(working copy)
@@ -938,10 +938,6 @@
 	    PVTS(r, page)->nscrolled = SVLINES;
 	else
 	    PVTS(r, page)->nscrolled = (uint16_t)nscrolled;
-	if (ISSET_OPTION(r, Opt_scrollWithBuffer) &&
-	    VSTART != 0 &&
-	    VSTART != SVLINES)
-	    rxvt_scr_page(r, page, UP, count);
     }
     else if (!spec)
 	row1 += SVLINES;
