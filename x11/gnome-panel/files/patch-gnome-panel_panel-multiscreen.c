--- gnome-panel/panel-multiscreen.c.orig	2009-10-12 22:57:08.000000000 +1000
+++ gnome-panel/panel-multiscreen.c	2009-10-12 22:57:08.000000000 +1000
@@ -136,9 +136,17 @@
 	xroot = GDK_WINDOW_XWINDOW (gdk_screen_get_root_window (screen));
 
 #if (RANDR_MAJOR > 1 || (RANDR_MAJOR == 1 && RANDR_MINOR >= 3))
-	if (have_randr_1_3)
+	if (have_randr_1_3) {
 		resources = XRRGetScreenResourcesCurrent (xdisplay, xroot);
-	else
+		if (resources->noutput == 0) {
+			/* This might happen if nothing tried to get randr
+			 * resources from the server before, so we need an
+			 * active probe. See comment #27 in
+			 * https://bugzilla.gnome.org/show_bug.cgi?id=597101 */
+			XRRFreeScreenResources (resources);
+			resources = XRRGetScreenResources (xdisplay, xroot);
+		}
+	} else
 		resources = XRRGetScreenResources (xdisplay, xroot);
 #else
 	resources = XRRGetScreenResources (xdisplay, xroot);
@@ -205,6 +213,17 @@
 		return FALSE;
 	}
 
+	if (geometries->len == 0) {
+		/* This can happen in at least one case:
+		 * https://bugzilla.novell.com/show_bug.cgi?id=543876 where all
+		 * monitors appear disconnected (possibly because the  screen
+		 * is behing a KVM switch) -- see comment #8.
+		 * There might be other cases too, so we stay on the safe side.
+		 */
+		g_array_free (geometries, TRUE);
+		return FALSE;
+	}
+
 	*monitors_ret = geometries->len;
 	*geometries_ret = (GdkRectangle *) g_array_free (geometries, FALSE);
 
@@ -238,9 +257,15 @@
 					       int           *monitors_ret,
 					       GdkRectangle **geometries_ret)
 {
-	if (panel_multiscreen_get_randr_monitors_for_screen (screen,
-							     monitors_ret,
-							     geometries_ret))
+	gboolean res;
+
+	*monitors_ret = 0;
+	*geometries_ret = NULL;
+
+	res = panel_multiscreen_get_randr_monitors_for_screen (screen,
+							       monitors_ret,
+							       geometries_ret);
+	if (res && *monitors_ret > 0)
 		return;
 
 	panel_multiscreen_get_gdk_monitors_for_screen (screen,
