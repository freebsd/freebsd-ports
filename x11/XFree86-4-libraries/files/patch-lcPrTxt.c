--- lib/X11/lcPrTxt.c.orig	Mon Jun  3 15:36:00 2002
+++ lib/X11/lcPrTxt.c	Mon Apr 21 23:38:30 2003
@@ -154,7 +154,6 @@
 	    buf_len = text_prop->nitems * 6 + 1;
 	else
 	    buf_len = text_prop->nitems * XLC_PUBLIC(lcd, mb_cur_max) + 1;
-	buf = (XPointer) Xmalloc(buf_len);
     }
     buf = (XPointer) Xmalloc(buf_len);
     if (buf == NULL)
