--- src/applications-view.c.orig	2014-08-26 15:48:00 UTC
+++ src/applications-view.c
@@ -949,7 +949,7 @@ static void xfdashboard_applications_vie
 	/* Set up view */
 	xfdashboard_view_set_internal_name(XFDASHBOARD_VIEW(self), "applications");
 	xfdashboard_view_set_name(XFDASHBOARD_VIEW(self), _("Applications"));
-	xfdashboard_view_set_icon(XFDASHBOARD_VIEW(self), GTK_STOCK_HOME);
+	xfdashboard_view_set_icon(XFDASHBOARD_VIEW(self), "go-home");
 
 	/* Set up actor */
 	xfdashboard_actor_set_can_focus(XFDASHBOARD_ACTOR(self), TRUE);
