--- lib/libxview/ttysw/ttyansi.c.orig	2005-03-28 06:41:31.000000000 -0800
+++ lib/libxview/ttysw/ttyansi.c	2012-02-03 12:45:50.351507890 -0800
@@ -31,6 +31,9 @@
 #include <xview_private/ttyansi.h>
 
 #include <xview/sel_attrs.h>
+static int    send_input_to_textsw();
+static int    ansi_lf();
+static int    ansi_char();
 
 char           *textsw_checkpoint_undo();
 Textsw_index    textsw_replace_i18n(), textsw_erase_i18n();
