--- xfce4-session/shutdown.c.orig	Sun Apr 18 10:41:07 2004
+++ xfce4-session/shutdown.c	Sun Apr 18 10:49:51 2004
@@ -170,7 +170,8 @@
 
 	/* Try to grab Input on a hidden window first */
 	hidden = gtk_invisible_new();
-	gtk_widget_show(hidden);
+	gtk_widget_show_now(hidden);
+	gdk_flush();
 
 	for (;;) {
 		if (gdk_pointer_grab(hidden->window, FALSE, 0, NULL, NULL,
@@ -201,16 +202,23 @@
 
 	/* this window *should* not be handled by the window manager */
 	g_object_set(G_OBJECT(dialog), "type", GTK_WINDOW_POPUP, NULL);
+	if ((gtk_major_version >=2) && (gtk_minor_version >= 3)) {
+		g_object_set (G_OBJECT (dialog), "type_hint",
+			      GDK_WINDOW_TYPE_HINT_UTILITY, NULL);
+	}
+	g_object_set (G_OBJECT (dialog), "decorated", FALSE, NULL);
 
 	/*
 	 * Grabbing the Xserver when accessibility is enabled will cause a
 	 * hang. Found in gnome-session (see #93103 for details).
 	 */
 	accessibility = GTK_IS_ACCESSIBLE(gtk_widget_get_accessible(dialog));
-	if (!accessibility) {
-		gdk_x11_grab_server();
-		drawBackground();
-		gdk_flush();
+	if ((gtk_major_version >=2) && (gtk_minor_version < 3)) {
+		if (!accessibility) {
+			gdk_x11_grab_server();
+			drawBackground();
+			gdk_flush();
+		}
 	}
 
 	dbox = GTK_DIALOG(dialog)->vbox;
@@ -300,10 +308,12 @@
 
 	gtk_widget_destroy(dialog);
 
-	/* ungrab the Xserver */
-	if (!accessibility) {
-		gdk_x11_ungrab_server();
-		refreshBackground();
+	if ((gtk_major_version >=2) && (gtk_minor_version < 3)) {
+		/* ungrab the Xserver */
+		if (!accessibility) {
+			gdk_x11_ungrab_server();
+			refreshBackground();
+		}
 	}
 
 	/* Release Keyboard/Mouse pointer grab */
