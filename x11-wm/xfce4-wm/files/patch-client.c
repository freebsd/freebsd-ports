--- src/client.c.orig	2007-04-02 21:48:20.000000000 +0200
+++ src/client.c	2007-10-25 22:26:36.000000000 +0200
@@ -4868,21 +4868,19 @@
 
     if (passdata.c)
     {
-        GdkPixbuf *icon;
-
         TRACE ("entering cycle loop");
         passdata.wireframe = wireframeCreate (passdata.c);
-        icon = getAppIcon (display_info, passdata.c->window, 32, 32);
         passdata.tabwin = tabwinCreate (passdata.c->screen_info->gscr, c,
                                         passdata.c, passdata.cycle_range,
                                         screen_info->params->cycle_workspaces);
         eventFilterPush (display_info->xfilter, clientCycleEventFilter, &passdata);
         gtk_main ();
         eventFilterPop (display_info->xfilter);
-        wireframeDelete (screen_info, passdata.wireframe);
         TRACE ("leaving cycle loop");
         tabwinDestroy (passdata.tabwin);
         g_free (passdata.tabwin);
+        wireframeDelete (screen_info, passdata.wireframe);
+        updateXserverTime (display_info);
     }
 
     if (passdata.c)
