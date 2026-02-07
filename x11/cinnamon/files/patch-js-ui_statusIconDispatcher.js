--- js/ui/statusIconDispatcher.old.js	2013-02-26 15:18:27.696454220 +0100
+++ js/ui/statusIconDispatcher.js	2013-02-26 15:19:02.768452834 +0100
@@ -8,11 +8,9 @@
 
 
 const STANDARD_TRAY_ICON_IMPLEMENTATIONS = {
-    'bluetooth-applet': 'bluetooth',
     'gnome-volume-control-applet': 'volume', // renamed to gnome-sound-applet
                                              // when moved to control center                                                
     'gnome-sound-applet': 'volume',
-    'nm-applet': 'network',
     'gnome-power-manager': 'battery',
     'keyboard': 'keyboard',
     'a11y-keyboard': 'a11y',
