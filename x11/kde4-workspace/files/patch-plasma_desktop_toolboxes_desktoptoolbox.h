* Add handler for change of mutability of the desktop toolbox
*
--- plasma/desktop/toolboxes/desktoptoolbox.h.orig	2015-06-26 03:17:21 UTC
+++ plasma/desktop/toolboxes/desktoptoolbox.h
@@ -81,6 +81,7 @@ protected Q_SLOTS:
      * show/hide the toolbox
      */
     void toggle();
+    void immutabilityChanged(Plasma::ImmutabilityType immutability);
 
     // basic desktop controls
     void startLogout();
