--- src/brightside.c.orig	Fri Jul  2 01:21:09 2004
+++ src/brightside.c	Fri Jul  2 01:32:08 2004
@@ -140,12 +140,12 @@
 {
 	XWindowAttributes attributes;
 	WnckWindow *window = wnck_screen_get_active_window (screen);
+	GList *list = wnck_screen_get_windows (screen);
 	if (window) {
 		XGetWindowAttributes (display, wnck_window_get_xid (window), 
 				&attributes);
 		return attributes.root;
 	}
-	GList *list = wnck_screen_get_windows (screen);
 	if (list) {
 		window = g_list_first (list)->data;
 		XGetWindowAttributes (display, wnck_window_get_xid (window), 
@@ -740,10 +740,12 @@
 static gboolean
 update_bar_volume_cb (Brightside *brightside)
 {
+	gint vol;
+	GtkWidget *progress;
 	if (brightside->dialog_timeout == 0)
 		return FALSE;
-	gint vol = brightside_volume_get_volume (brightside->volobj);
-	GtkWidget *progress = glade_xml_get_widget (brightside->xml, 
+	vol = brightside_volume_get_volume (brightside->volobj);
+	progress = glade_xml_get_widget (brightside->xml, 
 			"progressbar");
 	gtk_progress_bar_set_fraction (GTK_PROGRESS_BAR (progress),
 			(double) vol / 100);
@@ -760,15 +762,17 @@
 static gboolean
 update_bar_timed_cb (Brightside *brightside)
 {
+	GTimeVal time_now;
+	GtkWidget *progress;
+	glong elapsed_msec;
 	if (brightside->dialog_timeout == 0)
 		return FALSE;
-	GTimeVal time_now;
 	g_get_current_time (&time_now);
-	glong elapsed_msec = ABS (TIMEVAL_ELAPSED_MSEC (time_now, 
+	elapsed_msec = ABS (TIMEVAL_ELAPSED_MSEC (time_now, 
 				brightside->time_progress_bar));
 	if (elapsed_msec > DIALOG_TIMEOUT)
 		return FALSE;
-	GtkWidget *progress = glade_xml_get_widget (brightside->xml, 
+	progress = glade_xml_get_widget (brightside->xml, 
 			"progressbar");
 	gtk_progress_bar_set_fraction (GTK_PROGRESS_BAR (progress),
 			(double) elapsed_msec / DIALOG_TIMEOUT);
@@ -1096,6 +1100,7 @@
 	GList *list = wnck_screen_get_windows (screen);
 	GList *tmp;
 	int i;
+	int j;
 	WnckWindow *windows [g_list_length (list)];
 
 	/* in bottom-to-top order */
@@ -1105,8 +1110,9 @@
 	for (i = 0, tmp = g_list_first (list); tmp != NULL; 
 			tmp = g_list_next (tmp)) {
 		WnckWindow *window = tmp->data;
+		WnckWindowType type;
 		g_assert (WNCK_IS_WINDOW (window));
-		WnckWindowType type = wnck_window_get_window_type (window);
+		type = wnck_window_get_window_type (window);
 		if (type == WNCK_WINDOW_NORMAL || type == WNCK_WINDOW_DIALOG
 				|| type == WNCK_WINDOW_TOOLBAR
 				|| type == WNCK_WINDOW_MENU
@@ -1115,11 +1121,12 @@
 			WnckWorkspace *workspace = wnck_window_get_workspace (
 					window);
 			Window xwindow = wnck_window_get_xid (window);
+			int wwidth, wheight, x, y, width, height;
+			XWindowAttributes attributes;
 			if (xwindow == avoid)
 				continue;
-			int wwidth = wnck_workspace_get_width (workspace);
-			int wheight = wnck_workspace_get_height (workspace);
-			int x, y, width, height;
+			wwidth = wnck_workspace_get_width (workspace);
+			wheight = wnck_workspace_get_height (workspace);
 			/* Trouble: this gets position of internal window,
 			 * not including decorations. However, XMoveWindow
 			 * moves the decorated window. So, use 
@@ -1127,7 +1134,6 @@
 			 * internal window from decorations. */
 			wnck_window_get_geometry (window, 
 					&x, &y, &width, &height);
-			XWindowAttributes attributes;
 			XGetWindowAttributes (xdisplay, xwindow, &attributes);
 			if ((edge == LEFT || edge == RIGHT) &&
 					!wnck_window_is_maximized (window) &&
@@ -1160,7 +1166,6 @@
 		}
 	}
 	/* Restack from top to bottom - XRestackWindows doesn't seem to work */
-	int j;
 	if (REGION_IS_EDGE (edge))
 		for (j = 0; j < i; ++j)
 			XLowerWindow (xdisplay, 
@@ -1176,20 +1181,20 @@
 		wnck_screen_get_active_workspace (brightside->screen);
 	int workspace_index = wnck_workspace_get_number (active_workspace);
 	int workspace_count = wnck_screen_get_workspace_count (brightside->screen);
+	int n_columns, n_rows, new_index;
+	WnckWorkspace *new_workspace;
 
 	workspace_info *w_info = g_new (workspace_info, 1);
 	if (get_workspace_info (w_info, brightside) == FALSE) {
 		g_free (w_info);
 		return FALSE;
 	}
-	int n_columns = w_info->cols;
-	int n_rows = w_info->rows;
+	n_columns = w_info->cols;
+	n_rows = w_info->rows;
 	g_free (w_info);
 
-	int new_index = workspace_index;
+	new_index = workspace_index;
 
-	WnckWorkspace *new_workspace;
-	
 	if (event->type != GDK_SCROLL)
 		return FALSE;
 	
@@ -1270,10 +1275,11 @@
 pager_show (Brightside *brightside, WnckWorkspace *workspace, 
 		int n_rows, gboolean from_scroll)
 {
+	GtkWidget *label;
 #ifdef DEBUG
 	g_print("pager_show %d %d\n", n_rows, from_scroll);
 #endif
-	GtkWidget *label = glade_xml_get_widget (brightside->xml, 
+	label = glade_xml_get_widget (brightside->xml, 
 			"workspace_label");
 	gtk_label_set_text (GTK_LABEL (label), 
 			wnck_workspace_get_name (workspace));
@@ -1298,10 +1304,11 @@
 gboolean
 pager_enter_leave (GtkWidget *widget, GdkEventCrossing *event, gpointer data)
 {
+	Brightside *brightside;
 #ifdef DEBUG
 	g_print("pager_enter_leave %d %d\n", event->type, event->detail);
 #endif
-	Brightside *brightside = (Brightside *) data;
+	brightside = (Brightside *) data;
 	if (event->type == GDK_LEAVE_NOTIFY && 
 			event->detail != GDK_NOTIFY_INFERIOR)
 		gtk_widget_hide (brightside->pager);
@@ -1315,7 +1322,16 @@
 static void 
 do_edge_flip (Brightside *brightside, gint edge) /* or corner flip, now */
 {
-	int i;
+	int i, workspaces, current, cols, rows, original;
+	int new_space = 0;
+	gint starting_corner;
+	gboolean have_wrapped = FALSE;
+	gint wrapped_point = 0;
+	Display *xdisplay;
+	gboolean vertical_workspaces;
+	WnckWorkspace *new_workspace;
+	GdkScreen *screen;
+	gint oldx, oldy, x, y;
 
 #ifdef DEBUG
 	g_print ("Request edge flip: edge is %d\n", edge);
@@ -1325,12 +1341,12 @@
 		g_free (w_info);
 		return;
 	}
-	int workspaces = w_info->workspaces;
-	int current = w_info->current;
-	gboolean vertical_workspaces = w_info->vertical_workspaces;
-	gint starting_corner = w_info->starting_corner;
-	int cols = w_info->cols;
-	int rows = w_info->rows;
+	workspaces = w_info->workspaces;
+	current = w_info->current;
+	vertical_workspaces = w_info->vertical_workspaces;
+	starting_corner = w_info->starting_corner;
+	cols = w_info->cols;
+	rows = w_info->rows;
 	g_free (w_info);
 	g_return_if_fail (workspaces > 0);
 #ifdef DEBUG
@@ -1343,12 +1359,9 @@
 			brightside->settings.orientable_workspaces ?"":" not",
 			brightside->settings.edge_wrap ? "" : " not");
 #endif
-	int original = current;
+	original = current;
 
-	int new_space = 0;
-	gboolean have_wrapped = FALSE;
-	gint wrapped_point = 0;
-	Display *xdisplay = gdk_x11_display_get_xdisplay (brightside->display);
+	xdisplay = gdk_x11_display_get_xdisplay (brightside->display);
 
 #if 0
 	Window xmoving = None;
@@ -1383,11 +1396,12 @@
 	/* In order to handle gaps in the workspace layout: loop at most 
 	 * workspaces times */
 	for (i = 0; i < workspaces; ++i) {
+		gint current_row;
 		gint current_col = vertical_workspaces
 			? current / rows : current % cols;
 		if (starting_corner == NE || starting_corner == SE)
 			current_col = (cols - 1) - current_col;
-		gint current_row = vertical_workspaces
+		current_row = vertical_workspaces
 			? current % rows : current / cols;
 		if (starting_corner == SW || starting_corner == SE)
 			current_row = rows - 1 - current_row;
@@ -1507,14 +1521,12 @@
 #endif
 	}
 
-	WnckWorkspace *new_workspace = wnck_screen_get_workspace (
+	new_workspace = wnck_screen_get_workspace (
 			brightside->screen, new_space);
 	wnck_workspace_activate (new_workspace);
 
 	pager_show (brightside, new_workspace, rows, FALSE);
 	
-	GdkScreen *screen;
-	gint oldx, oldy, x, y;
 	gdk_display_get_pointer (brightside->display, &screen, 
 			&oldx, &oldy, NULL);
 	x = gdk_screen_get_width(screen);
@@ -1688,10 +1700,11 @@
 	} else if (brightside->region_at == region) {
 		/* Still in a region not yet triggered */
 		GTimeVal time_now;
+		glong elapsed_msec, delay;
 		g_get_current_time (&time_now);
-		glong elapsed_msec = TIMEVAL_ELAPSED_MSEC (time_now,
+		elapsed_msec = TIMEVAL_ELAPSED_MSEC (time_now,
 				brightside->time_region_entered);
-		glong delay = REGION_IS_CORNER (region)
+		delay = REGION_IS_CORNER (region)
 			? brightside->settings.corner_delay
 			: brightside->settings.edge_delay;
 		/* Check if it's time to trigger the region */
@@ -1732,10 +1745,11 @@
 					&& brightside->settings.corner_flip) ||
 				brightside->settings.edge_flip) {
 			GTimeVal time_now;
+			glong elapsed_msec, delay;
 			g_get_current_time (&time_now);
-			glong elapsed_msec = TIMEVAL_ELAPSED_MSEC (time_now,
+			elapsed_msec = TIMEVAL_ELAPSED_MSEC (time_now,
 					brightside->time_edge_flipped);
-			glong delay = 2 * MAX (
+			delay = 2 * MAX (
 					brightside->settings.corner_flip ?
 					brightside->settings.corner_delay : 0,
 					brightside->settings.edge_flip ?
@@ -1774,14 +1788,14 @@
 		if (!have_just_flipped && 
 				!REGION_CORNER_TO_ADJACENT_EDGE (
 					brightside->region_at, region)) {
+			gchar gesture [REGION_GESTURE_HISTORY + 1];
+			gchar *gesture_found;
 			for (i = 1; i < REGION_GESTURE_HISTORY; ++i)
 				brightside->gesture_history[i-1] = 
 					brightside->gesture_history[i];
 			brightside->gesture_history[i-1].region = region;
 			brightside->gesture_history[i-1].time_region_entered =
 					brightside->time_region_entered;
-			gchar gesture [REGION_GESTURE_HISTORY + 1];
-			gchar *gesture_found;
 			for (i = 0; i < REGION_GESTURE_HISTORY; ++i)
 				gesture[i] = 
 					(brightside->gesture_history[i].region
@@ -1795,12 +1809,13 @@
 #endif
 			if ((gesture_found = g_strrstr (gesture, 
 						EASTER_EGG_GESTURE))) {
+				glong elapsed_msec, delay;
 				i = (gint) (gesture_found - gesture);
-				glong elapsed_msec = TIMEVAL_ELAPSED_MSEC (
+				elapsed_msec = TIMEVAL_ELAPSED_MSEC (
 						brightside->time_region_entered,
 						brightside->gesture_history[i]
 						.time_region_entered);
-				glong delay = MAX (
+				delay = MAX (
 					brightside->settings.corner_delay,
 					brightside->settings.edge_delay)
 					* 6;
@@ -1842,11 +1857,6 @@
 main (int argc, char *argv[])
 {
 	Brightside *brightside;
-
-	bindtextdomain (GETTEXT_PACKAGE, GNOMELOCALEDIR);
-	bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
-	textdomain (GETTEXT_PACKAGE);
-
 	GnomeProgram *brightside_program = NULL;
 	gboolean show_pager = FALSE, show_version = FALSE;
 	struct poptOption cmd_options_table[] = {
@@ -1855,6 +1865,11 @@
 		{"version", 'v', POPT_ARG_NONE, &show_version, 0, 
 			_("Show the version of brightside"), NULL},
 		{0}};
+
+	bindtextdomain (GETTEXT_PACKAGE, GNOMELOCALEDIR);
+	bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
+	textdomain (GETTEXT_PACKAGE);
+
 	
 	brightside_program = gnome_program_init ("brightside", VERSION,
 			LIBGNOMEUI_MODULE,
