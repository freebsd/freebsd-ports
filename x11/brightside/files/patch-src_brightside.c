--- src/brightside.c.orig	Sun Mar 13 19:44:54 2005
+++ src/brightside.c	Sun Mar 13 19:47:26 2005
@@ -1253,7 +1253,7 @@
 
 	new_workspace = wnck_screen_get_workspace (brightside->screen, new_index);
 	if (new_workspace) {
-		wnck_workspace_activate (new_workspace);
+		wnck_workspace_activate (new_workspace, event->time);
 		pager_show (brightside, new_workspace, n_rows, TRUE);
 	}
 	
@@ -1540,7 +1540,7 @@
 
 	new_workspace = wnck_screen_get_workspace (
 			brightside->screen, new_space);
-	wnck_workspace_activate (new_workspace);
+	wnck_workspace_activate (new_workspace, gtk_get_current_event_time());
 
 	pager_show (brightside, new_workspace, rows, FALSE);
 	
