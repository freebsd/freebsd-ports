--- js/ui/panel.js.old	2013-04-28 19:22:35.753485501 +0000
+++ js/ui/panel.js	2013-04-28 19:23:28.059021301 +0000
@@ -910,13 +910,6 @@
     PANEL_ITEM_IMPLEMENTATIONS['bluetooth'] =
         imports.ui.status.bluetooth.Indicator;
 
-try {
-    PANEL_ITEM_IMPLEMENTATIONS['network'] =
-        imports.ui.status.network.NMApplet;
-} catch(e) {
-    log('NMApplet is not supported. It is possible that your NetworkManager version is too old');
-}
-
 const Panel = new Lang.Class({
     Name: 'Panel',
 
