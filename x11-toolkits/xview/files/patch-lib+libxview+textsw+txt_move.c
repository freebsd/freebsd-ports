--- ./lib/libxview/textsw/txt_move.c.orig	Tue Jun 29 07:17:47 1993
+++ ./lib/libxview/textsw/txt_move.c	Sat Apr  1 18:25:29 2000
@@ -55,7 +55,7 @@ static char     sccsid[] = "@(#)txt_move
 
 static int dnd_data_key = 0; /* XXX: Don't do this at home kids. */
 static int dnd_view_key = 0; 
-static int DndConvertProc();
+int DndConvertProc();
 
 Pkg_private Es_handle textsw_esh_for_span();
 Pkg_private Es_index ev_resolve_xy();
@@ -688,7 +688,7 @@ textsw_do_drag_copy_move(view, ie, is_co
     xv_destroy(dnd_accept_cursor);
 }
 
-static int
+int
 DndConvertProc(dnd, type, data, length, format)
     Dnd      	 dnd;
     Atom        *type;
