--- menu-cache-daemon/menu-cached.c.o	2011-03-17 10:58:03.876822788 -0400
+++ menu-cache-daemon/menu-cached.c	2011-03-17 10:58:49.355824755 -0400
@@ -341,6 +341,29 @@
                       GFileMonitorEvent evt, Cache* cache )
 {
     /* DEBUG("file %s is changed (%d).", g_file_get_path(gf), evt); */
+
+    if ( evt == G_FILE_MONITOR_EVENT_DELETED )
+    {
+        int idx;
+        /* dirty hack: get index of the monitor in array */
+        for(idx = 0; idx < cache->n_files; ++idx)
+        {
+            if(mon == cache->mons[idx])
+                break;
+        }
+
+        /* Check if this file or directory was already removed from the cache */
+        char* changed_file = g_file_get_path(gf);
+        char* dir_path = cache->files[idx]+1;
+        int len = strlen(dir_path);
+        char* base_name = changed_file + len + 1;
+        gboolean in_cache = is_desktop_file_in_cache(cache, idx, g_file_get_path(gf));
+        if( ! in_cache ) { /* Means this file was already deleted, no need to refresh cache */
+          DEBUG("files are changed, but no re-generation is needed.");
+          return;
+        }
+    }
+
     /* if( mon != cache->cache_mon ) */
     {
         /* Optimization: Some files in the dir are changed, but it
