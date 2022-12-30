diff --git libcvc/gvc-channel-map.c libcvc/gvc-channel-map.c
index 7f14c8b..69682ac 100644
--- libcvc/gvc-channel-map.c
+++ libcvc/gvc-channel-map.c
@@ -109,7 +109,7 @@ gvc_channel_map_set_balance (GvcChannelMap *map,
 {
         pa_cvolume cv;
 
-        g_return_val_if_fail (GVC_IS_CHANNEL_MAP (map), NULL);
+        g_return_if_fail (GVC_IS_CHANNEL_MAP (map));
 
         if (!gvc_channel_map_can_balance (map))
                 return;
@@ -149,7 +149,7 @@ gvc_channel_map_set_fade (GvcChannelMap *map,
 {
         pa_cvolume cv;
 
-        g_return_val_if_fail (GVC_IS_CHANNEL_MAP (map), NULL);
+        g_return_if_fail (GVC_IS_CHANNEL_MAP (map));
 
         if (!gvc_channel_map_can_fade (map))
                 return;
@@ -191,7 +191,7 @@ gvc_channel_map_set_lfe (GvcChannelMap *map,
 {
         pa_cvolume cv;
 
-        g_return_val_if_fail (GVC_IS_CHANNEL_MAP (map), NULL);
+        g_return_if_fail (GVC_IS_CHANNEL_MAP (map));
 
         if (!gvc_channel_map_has_lfe (map))
                 return;
