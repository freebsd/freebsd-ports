--- ./lib/libxview/ttysw/ttyansi.c.orig	Tue Jun 29 07:17:21 1993
+++ ./lib/libxview/ttysw/ttyansi.c	Sat Apr  1 18:25:30 2000
@@ -31,6 +31,10 @@ static char     sccsid[] = "@(#)ttyansi.
 
 #include <xview/sel_attrs.h>
 
+static int	send_input_to_textsw();
+static int	ansi_lf();
+static int	ansi_char();
+
 char           *strncpy();
 char           *textsw_checkpoint_undo();
 Textsw_index    textsw_replace_i18n(), textsw_erase_i18n();
