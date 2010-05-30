--- ./keynav.c.orig	2010-05-30 11:20:37.002333962 -0400
+++ ./keynav.c	2010-05-30 11:20:57.051721006 -0400
@@ -881,14 +881,14 @@
     xdo_mouseup(xdo, CURRENTWINDOW, button);
   } else { /* Start dragging */
     appstate.dragging = True;
-    xdo_keysequence_down(xdo, 0, drag_modkeys);
+    xdo_keysequence_down(xdo, 0, drag_modkeys, 0);
     xdo_mousedown(xdo, CURRENTWINDOW, button);
 
     /* Sometimes we need to move a little to tell the app we're dragging */
     /* TODO(sissel): Make this a 'mousewiggle' command */
     xdo_mousemove_relative(xdo, 1, 0);
     xdo_mousemove_relative(xdo, -1, 0);
-    xdo_keysequence_up(xdo, 0, drag_modkeys);
+    xdo_keysequence_up(xdo, 0, drag_modkeys, 0);
   }
 }
 
