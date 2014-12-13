--- applets/wncklet/workspace-switcher.c.orig
+++ applets/wncklet/workspace-switcher.c
@@ -143,7 +143,7 @@
 
 	if (!wm_name)
 		pager->wm = PAGER_WM_UNKNOWN;
-	else if (strcmp(wm_name, "Marco") == 0)
+	else if (strcmp(wm_name, "Metacity (Marco)") == 0)
 		pager->wm = PAGER_WM_MARCO;
 	else if (strcmp(wm_name, "Compiz") == 0)
 		pager->wm = PAGER_WM_COMPIZ;
