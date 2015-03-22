--- src/search-view.c.orig	2014-08-26 15:48:00 UTC
+++ src/search-view.c
@@ -1052,7 +1052,7 @@ static void xfdashboard_search_view_init
 	/* Set up view (Note: Search view is disabled by default!) */
 	xfdashboard_view_set_internal_name(XFDASHBOARD_VIEW(self), "search");
 	xfdashboard_view_set_name(XFDASHBOARD_VIEW(self), _("Search"));
-	xfdashboard_view_set_icon(XFDASHBOARD_VIEW(self), GTK_STOCK_FIND);
+	xfdashboard_view_set_icon(XFDASHBOARD_VIEW(self), "edit-find");
 	xfdashboard_view_set_enabled(XFDASHBOARD_VIEW(self), FALSE);
 
 	/* Set up actor */
