From 88d469cb47e58865370b26e6a4d6a7f8891d2949 Mon Sep 17 00:00:00 2001
From: Andre Miranda <andreldm@xfce.org>
Date: Sun, 25 Aug 2019 19:16:03 -0300
Subject: [PATCH] pager: Override WnckPager scroll-event handler (Bug #15886)

---
 plugins/pager/pager.c | 2 ++
 1 file changed, 2 insertions(+)

diff --git a/plugins/pager/pager.c b/plugins/pager/pager.c
index 5637bea6..3a64496e 100644
--- plugins/pager/pager.c
+++ plugins/pager/pager.c
@@ -445,6 +445,8 @@ G_GNUC_END_IGNORE_DEPRECATIONS
                               G_CALLBACK (pager_plugin_drag_begin_event), plugin);
       g_signal_connect_after (G_OBJECT (plugin->pager), "drag-end",
                               G_CALLBACK (pager_plugin_drag_end_event), plugin);
+      g_signal_connect_swapped (G_OBJECT (plugin->pager), "scroll-event",
+                                G_CALLBACK (pager_plugin_scroll_event), plugin);
     }
   else
     {
-- 
2.23.0

