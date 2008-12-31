diff -urbB ../WindowMaker-0.92.0/src/switchpanel.c ./src/switchpanel.c
--- ../WindowMaker-0.92.0/src/switchpanel.c	2004-10-30 00:16:04.000000000 -0700
+++ ./src/switchpanel.c	2008-12-14 19:59:05.000000000 -0800
@@ -464,7 +464,7 @@
     iconsThatFitCount= count;
 
     if (width > rect.size.width) {
-        iconsThatFitCount = (WMScreenWidth(scr->wmscreen)-SCREEN_BORDER_SPACING)/ICON_TILE_SIZE;
+        iconsThatFitCount = (rect.size.width-SCREEN_BORDER_SPACING)/ICON_TILE_SIZE;
         width= iconsThatFitCount*ICON_TILE_SIZE;
     }
     
@@ -501,6 +501,7 @@
 
     if (!panel->bg) {
         WMFrame *frame = WMCreateFrame(panel->win);
+        WMColor *darkGray = WMDarkGrayColor(scr->wmscreen);
         WMSetFrameRelief(frame, WRSimple);
         WMSetViewExpandsToParent(WMWidgetView(frame), 0, 0, 0, 0);
         
@@ -508,10 +509,11 @@
         WMResizeWidget(panel->label, width, LABEL_HEIGHT);
         WMMoveWidget(panel->label, BORDER_SPACE, BORDER_SPACE+ICON_TILE_SIZE+5);
         WMSetLabelRelief(panel->label, WRSimple);
-        WMSetWidgetBackgroundColor(panel->label, WMDarkGrayColor(scr->wmscreen));
+        WMSetWidgetBackgroundColor(panel->label, darkGray);
         WMSetLabelFont(panel->label, panel->font);
         WMSetLabelTextColor(panel->label, panel->white);
         
+        WMReleaseColor(darkGray);
         height+= 5;
     }
     
@@ -604,6 +606,8 @@
       RReleaseImage(panel->bg);
     if (panel->font)
       WMReleaseFont(panel->font);
+    if (panel->white)
+      WMReleaseColor(panel->white);
     wfree(panel);
 }
 
