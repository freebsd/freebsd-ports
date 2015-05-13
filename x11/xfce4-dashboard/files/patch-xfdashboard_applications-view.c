--- xfdashboard/applications-view.c.orig	2015-03-04 05:45:24 UTC
+++ xfdashboard/applications-view.c
@@ -1374,7 +1374,7 @@ static void xfdashboard_applications_vie
 	/* Set up view */
 	xfdashboard_view_set_internal_name(XFDASHBOARD_VIEW(self), "applications");
 	xfdashboard_view_set_name(XFDASHBOARD_VIEW(self), _("Applications"));
-	xfdashboard_view_set_icon(XFDASHBOARD_VIEW(self), "gtk-home");
+	xfdashboard_view_set_icon(XFDASHBOARD_VIEW(self), "go-home");
 
 	/* Set up actor */
 	xfdashboard_actor_set_can_focus(XFDASHBOARD_ACTOR(self), TRUE);
