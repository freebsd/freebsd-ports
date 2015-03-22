--- src/windows-view.c.orig	2014-08-26 15:48:01 UTC
+++ src/windows-view.c
@@ -87,7 +87,7 @@ static XfdashboardLiveWindow* _xfdashboa
 static void _xfdashboard_windows_view_set_active_workspace(XfdashboardWindowsView *self, XfdashboardWindowTrackerWorkspace *inWorkspace);
 
 /* IMPLEMENTATION: Private variables and methods */
-#define DEFAULT_VIEW_ICON			GTK_STOCK_FULLSCREEN
+#define DEFAULT_VIEW_ICON			"view-fullscreen"
 #define DEFAULT_DRAG_HANDLE_SIZE	32.0f
 
 /* Check if window should be shown */
