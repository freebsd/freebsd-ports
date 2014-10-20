Obtained from:
- Fullscreen mode doesn't work correctly for Chromium (bug #8563)
- Panels don't hide when full screening VLC, which is maximized (bug #10622)

--- src/client.c.orig	2013-05-05 15:58:42 UTC
+++ src/client.c
@@ -981,8 +981,13 @@
         wc.width = c->width;
         wc.height = c->height;
 
+        if (FLAG_TEST (c->flags, CLIENT_FLAG_FULLSCREEN))
+        {
+            clientUpdateFullscreenSize (c);
+        }
+
         /* If client is maximized, we need to update its coordonates and size as well */
-        if (FLAG_TEST (c->flags, CLIENT_FLAG_MAXIMIZED))
+        else if (FLAG_TEST (c->flags, CLIENT_FLAG_MAXIMIZED))
         {
             GdkRectangle rect;
             myScreenFindMonitorAtPoint (screen_info,
@@ -3538,8 +3543,13 @@
             continue;
         }
 
+        if (FLAG_TEST (c->flags, CLIENT_FLAG_FULLSCREEN))
+        {
+            clientUpdateFullscreenSize (c);
+        }
+
         /* Recompute size and position of maximized windows */
-        if (FLAG_TEST (c->flags, CLIENT_FLAG_MAXIMIZED))
+        else if (FLAG_TEST (c->flags, CLIENT_FLAG_MAXIMIZED))
         {
             maximization_flags = c->flags & CLIENT_FLAG_MAXIMIZED;
 
@@ -3553,10 +3563,6 @@
             wc.height = c->height;
             clientConfigure (c, &wc, CWX | CWY | CWWidth | CWHeight, CFG_NOTIFY);
         }
-        else if (FLAG_TEST (c->flags, CLIENT_FLAG_FULLSCREEN))
-        {
-            clientUpdateFullscreenSize (c);
-        }
         else
         {
             configure_flags = CFG_CONSTRAINED | CFG_REQUEST;
