--- ./lib/libxview/ttysw/ttyselect.c.orig	Sun Jun 26 03:05:23 1994
+++ ./lib/libxview/ttysw/ttyselect.c	Sat Apr  1 18:25:30 2000
@@ -75,6 +75,8 @@ static Seln_result ttysel_copy_in(),
 #endif
                 ttysel_reply();
 
+static ttysel_resynch();
+
 static struct ttyselection *
                 ttysel_from_rank();
 
