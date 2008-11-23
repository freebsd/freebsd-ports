diff -Naur ./src/Frame.cc ../pekwm-0.1.8/src/Frame.cc
--- ./src/Frame.cc	2008-11-20 20:20:55.000000000 +0100
+++ ../pekwm-0.1.8/src/Frame.cc	2008-11-20 20:21:20.000000000 +0100
@@ -1990,7 +1990,7 @@
 Frame::handleConfigureRequestGeometry(XConfigureRequestEvent *ev, Client *client)
 {
     // Look for fullscreen requests
-    long all_geometry = CWX|CWY|CWWidth|CWHeight;
+    const long all_geometry = CWX|CWY|CWWidth|CWHeight;
     bool is_fullscreen = false;
     if (Config::instance()->isFullscreenDetect()
         && ! client->isCfgDeny(CFG_DENY_SIZE)
@@ -2007,16 +2007,15 @@
     }
 
     if (! is_fullscreen) {
-        // Remove fullscreen state if client changes it size
-        if (Config::instance()->isFullscreenDetect()) {
-            setStateFullscreen(STATE_UNSET);
-        }
+        bool change_geometry = false;
 
         if (! client->isCfgDeny(CFG_DENY_SIZE)
                 && (ev->value_mask & (CWWidth|CWHeight)) ) {
 
             resizeChild(ev->width, ev->height);
             _client->setShaped(setShape());
+
+           change_geometry = true;
         }
 
         if (! client->isCfgDeny(CFG_DENY_POSITION)
@@ -2025,6 +2024,13 @@
             calcGravityPosition(_client->getXSizeHints()->win_gravity,
                                 ev->x, ev->y, _gm.x, _gm.y);
             move(_gm.x, _gm.y);
+
+           change_geometry = true;
+        }
+
+        // Remove fullscreen state if client changes it size
+        if (change_geometry && Config::instance()->isFullscreenDetect()) {
+            setStateFullscreen(STATE_UNSET);
         }
     }
 }
