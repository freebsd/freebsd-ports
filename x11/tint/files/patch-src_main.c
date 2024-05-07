--- src/main.c.orig	2024-04-13 07:17:11 UTC
+++ src/main.c
@@ -419,6 +419,9 @@ void handle_x_event(XEvent *e)
     if (handle_x_event_autohide(e))
         return;

+	if ((e->type==4 || e->type==5 || e->type==6) && e->xproperty.window==server.root_win)
+		return;
+
     Panel *panel = get_panel(e->xany.window);
     switch (e->type) {
     case ButtonPress: {
