--- src/gtk-style.c.orig	Sat Feb  8 16:17:37 2003
+++ src/gtk-style.c	Sat Feb  8 16:18:39 2003
@@ -97,12 +97,6 @@
 {
 /* If GTK_MINOR_VERSION is not 2 we are using gtk+ 1.3.x or 2.0
    so these two members are no more */
-#if (GTK_MINOR_VERSION == 2)
-    if (rc->font_name != 0)
-	printf ("(font . \"%s\")\n", rc->font_name);
-    if (rc->fontset_name != 0)
-	printf ("(fontset . \"%s\")\n", rc->fontset_name);
-#endif
     if (print_rc_colors ("fg", rc->fg, 5, rc->color_flags, GTK_RC_FG))
     	print_colors ("fg", style->fg, 5);
     if (print_rc_colors ("bg", rc->bg, 5, rc->color_flags, GTK_RC_BG))
