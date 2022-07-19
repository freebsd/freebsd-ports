--- modules/FvwmIconMan/x.c.orig	2022-07-18 23:18:50 UTC
+++ modules/FvwmIconMan/x.c
@@ -742,6 +742,7 @@ void X_init_manager (int man_id)
     char *scr;
     fscreen_scr_arg arg;
     arg.mouse_ev = NULL;
+    arg.name = NULL;
 
     geometry_mask = FScreenParseGeometryWithScreen(
       man->geometry_str, &man->geometry.x, &man->geometry.y,
