--- lib/libxview/textsw/txt_menu.c.orig	Sun Mar 26 01:01:17 2006
+++ lib/libxview/textsw/txt_menu.c	Sun Mar 26 01:02:52 2006
@@ -129,6 +129,8 @@
 
 
 /* VARARGS0 */
+static int	textsw_edit_do_menu_action(), textsw_view_do_menu_action(),
+		textsw_find_do_menu_action();
 static void
 textsw_new_menu(folio)
     Textsw_folio    folio;
@@ -140,8 +142,6 @@
     Frame           frame = xv_get(textsw, WIN_FRAME);
     Menu_item       break_mode_item, undo_cmds_item, find_sel_cmds_item,
                     select_field_cmds_item;
-    static int      textsw_edit_do_menu_action(), textsw_view_do_menu_action(),
-                    textsw_find_do_menu_action();
     int             index;
     Pkg_private char *textsw_get_extras_filename();
     Pkg_private int textsw_build_extras_menu_items();
