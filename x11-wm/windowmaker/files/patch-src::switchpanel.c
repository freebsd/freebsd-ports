--- src/switchpanel.c.orig	Sat Oct 23 10:56:59 2004
+++ src/switchpanel.c	Sun Oct 24 02:56:19 2004
@@ -198,8 +198,8 @@
 static void addIconForWindow(WSwitchPanel *panel, WWindow *wwin, int iconWidth)
 {
   WMLabel *label= WMCreateLabel(panel->hbox);
-  WMAddBoxSubviewAtEnd(panel->hbox, WMWidgetView(label), False, True, iconWidth + ICON_EXTRASPACE, 0, 0);
   RImage *image = NULL;
+  WMAddBoxSubviewAtEnd(panel->hbox, WMWidgetView(label), False, True, iconWidth + ICON_EXTRASPACE, 0, 0);
 
   if (!WFLAGP(wwin, always_user_icon) && wwin->net_icon_image)
       image = RRetainImage(wwin->net_icon_image);
