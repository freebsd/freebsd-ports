--- lib/libxview/textsw/txt_field.c.orig	Sun Mar 26 01:09:21 2006
+++ lib/libxview/textsw/txt_field.c	Sun Mar 26 01:10:42 2006
@@ -121,8 +121,6 @@
 		    CHAR            marker2[3];
 		    int             marker2_len;
 		    unsigned        direction;
-		    static void     textsw_get_match_symbol();
-
 		    buf = buf + (buf_len - marker1_len);
 		    (void) textsw_get_match_symbol(marker1, marker1_len,
 					 marker2, &marker2_len, &direction);
@@ -152,8 +150,6 @@
 		    CHAR            marker2[3];
 		    int             marker2_len;
 		    unsigned        direction;
-		    static void     textsw_get_match_symbol();
-
 		    (void) textsw_get_match_symbol(marker1, marker1_len,
 					 marker2, &marker2_len, &direction);
 		    if (STRNCMP(buf, marker2, marker2_len) == 0) {
