--- ./lib/libxview/textsw/ev_op_bdry.c.orig	Tue Jun 29 07:17:30 1993
+++ ./lib/libxview/textsw/ev_op_bdry.c	Sat Apr  1 18:25:28 2000
@@ -28,6 +28,9 @@ Pkg_private void ev_clear_from_margins()
 static Ev_finger_handle ev_insert_finger();
 static Ev_mark_object last_generated_id;
 
+static int ev_find_finger_internal();
+static ev_remove_finger_internal();
+
 #define FORALL(index_var)						\
 	for (index_var = 0; index_var < fingers->last_plus_one; index_var++)
 
