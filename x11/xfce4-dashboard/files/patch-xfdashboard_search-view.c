--- xfdashboard/search-view.c.orig	2015-03-04 05:44:14 UTC
+++ xfdashboard/search-view.c
@@ -1540,7 +1540,7 @@ static void xfdashboard_search_view_init
 	/* Set up view (Note: Search view is disabled by default!) */
 	xfdashboard_view_set_internal_name(XFDASHBOARD_VIEW(self), "search");
 	xfdashboard_view_set_name(XFDASHBOARD_VIEW(self), _("Search"));
-	xfdashboard_view_set_icon(XFDASHBOARD_VIEW(self), "gtk-find");
+	xfdashboard_view_set_icon(XFDASHBOARD_VIEW(self), "system-search");
 	xfdashboard_view_set_enabled(XFDASHBOARD_VIEW(self), FALSE);
 
 	/* Set up actor */
