--- src/slirprc-gtk.sl.orig	2009-09-27 23:31:51.000000000 -0400
+++ src/slirprc-gtk.sl	2009-09-27 23:32:06.000000000 -0400
@@ -308,6 +308,8 @@ accepts_null_args["g_list_append"] = [1]
 gtk_widget_get_window			% prefer my version, which returns
    					% bin_window for GtkLayout
 
+gtk_widget_get_allocation
+
 gtk_accel_group_activate		% gtk/gtkaccelgroup.h: "internal" funcs
 gtk_accel_group_get_entry
 gtk_accel_group_lock_entry
