--- src/brightside-tray.c.orig	Fri Jul  2 01:19:28 2004
+++ src/brightside-tray.c	Fri Jul  2 01:19:56 2004
@@ -51,6 +51,7 @@
 	const gchar *authors[] = { "Ed Catmur <ed@catmur.co.uk>", NULL };
 	const gchar *documenters[] = { NULL };
 	const gchar *translator_credits = _("translator_credits");
+	gpointer about_as_gpointer;
 
 	if (about != NULL) {
 		gdk_window_raise (about->window);
@@ -74,7 +75,7 @@
 	
 	g_signal_connect (G_OBJECT (about), "destroy",
 			G_CALLBACK (gtk_widget_destroyed), &about);
-	gpointer about_as_gpointer = (gpointer) about;
+	about_as_gpointer = (gpointer) about;
 	g_object_add_weak_pointer (G_OBJECT (about), &about_as_gpointer);
 
 	gtk_widget_show(about);
