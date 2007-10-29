--- src/main.c.orig	2007-08-12 17:00:01.000000000 -0400
+++ src/main.c	2007-10-29 15:27:28.000000000 -0400
@@ -3477,11 +3477,11 @@
 	WnckWindow *win;
 	decor_t *d;
 
-	win = wnck_screen_get_active_window(screen);
+	win = wnck_screen_get_previously_active_window(screen);
 	if (win)
 	{
 		d = g_object_get_data(G_OBJECT(win), "decor");
-		if (d->pixmap && d->decorated)
+		if (d && d->pixmap && d->decorated)
 		{
 			d->active = wnck_window_is_active(win);
 			d->fs = (d->active ? d->fs->ws->fs_act : d->fs->ws->fs_inact);
@@ -3493,11 +3493,11 @@
 		}
 	}
 
-	win = wnck_screen_get_previously_active_window(screen);
+	win = wnck_screen_get_active_window(screen);
 	if (win)
 	{
 		d = g_object_get_data(G_OBJECT(win), "decor");
-		if (d->pixmap && d->decorated)
+		if (d && d->pixmap && d->decorated)
 		{
 			d->active = wnck_window_is_active(win);
 			d->fs = (d->active ? d->fs->ws->fs_act : d->fs->ws->fs_inact);
@@ -3558,6 +3558,8 @@
 	if (!get_window_prop(wnck_window_get_xid(win), select_window_atom, &window))
 		remove_frame_window(win);
 
+	g_object_set_data (G_OBJECT (win), "decor", NULL);
+
 	g_free(d);
 }
 
@@ -5567,7 +5569,7 @@
 
     if (status != DECOR_ACQUIRE_STATUS_SUCCESS)
     {
-		if (status == DECOR_ACQUIRE_STATUS_OTHER_DM_RUNNING)
+		if (status == DECOR_ACQUIRE_STATUS_FAILED)
 		{
 			fprintf (stderr,
 				 "%s: Could not acquire decoration manager "
