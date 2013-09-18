--- cursors.c.orig	Tue Sep 22 22:16:04 1998
+++ cursors.c	Tue Sep 22 22:16:12 1998
@@ -278,7 +278,7 @@
 	    if (our_copy[0] == 'X')
 		font_file = "cursor";
 	    else if (our_copy[0] == 'O')
-		font_file = "-sun-open look cursor-----12-120-75-75-p-455-sunolcursor-1";
+		font_file = "-sun-open look cursor-----12-120-75-75-p-160-sunolcursor-1";
 	    createCursor(dpy, cmap, pointer, cursor_id, font_file, end, ptr);
 	}
 	else {
