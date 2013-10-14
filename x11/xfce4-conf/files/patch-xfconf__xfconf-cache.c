--- ./xfconf/xfconf-cache.c.orig	2012-04-28 19:51:47.000000000 +0000
+++ ./xfconf/xfconf-cache.c	2013-03-08 20:38:01.000000000 +0000
@@ -47,10 +47,16 @@
 
 #define ALIGN_VAL(val, align)  ( ((val) + ((align) -1)) & ~((align) - 1) )
 
-static void xfconf_cache_mutex_lock(GStaticMutex *mtx) __attribute__((noinline));
-static void xfconf_cache_mutex_lock(GStaticMutex *mtx) { g_static_mutex_lock(mtx); }
-static void xfconf_cache_mutex_unlock(GStaticMutex *mtx) __attribute__((noinline));
-static void xfconf_cache_mutex_unlock(GStaticMutex *mtx) { g_static_mutex_unlock(mtx); }
+
+
+#if GLIB_CHECK_VERSION (2, 32, 0)
+#define xfconf_cache_mutex_lock(cache)   g_mutex_lock (&(cache)->cache_lock)
+#define xfconf_cache_mutex_unlock(cache) g_mutex_unlock (&(cache)->cache_lock)
+#else
+#define xfconf_cache_mutex_lock(cache)   g_mutex_lock ((cache)->cache_lock)
+#define xfconf_cache_mutex_unlock(cache) g_mutex_unlock ((cache)->cache_lock)
+#endif
+
 
 
 /**************** XfconfCacheItem ****************/
@@ -210,7 +216,11 @@
     GHashTable *pending_calls;
     GHashTable *old_properties;
 
-    GStaticMutex cache_lock;
+#if GLIB_CHECK_VERSION (2, 32, 0)
+    GMutex cache_lock;
+#else
+    GMutex *cache_lock;
+#endif
 };
 
 typedef struct _XfconfCacheClass
@@ -347,7 +357,11 @@
     cache->old_properties = g_hash_table_new_full(g_str_hash, g_str_equal,
                                                   NULL, NULL);
 
-    g_static_mutex_init(&cache->cache_lock);
+#if GLIB_CHECK_VERSION (2, 32, 0)
+    g_mutex_init (&cache->cache_lock);
+#else
+    cache->cache_lock = g_mutex_new ();
+#endif
 }
 
 static void
@@ -433,7 +447,9 @@
     g_tree_destroy(cache->properties);
     g_hash_table_destroy(cache->old_properties);
 
-    g_static_mutex_free(&cache->cache_lock);
+#if !GLIB_CHECK_VERSION (2, 32, 0)
+    g_mutex_free (cache->cache_lock);
+#endif
 
     G_OBJECT_CLASS(xfconf_cache_parent_class)->finalize(obj);
 }
@@ -508,7 +524,7 @@
     if(!cache->pending_calls)
         return;
 
-    xfconf_cache_mutex_lock(&cache->cache_lock);
+    xfconf_cache_mutex_lock(cache);
 
     old_item = g_hash_table_lookup(cache->pending_calls, call);
     if(G_UNLIKELY(!old_item)) {
@@ -547,12 +563,12 @@
         }
 
         /* we need to drop the lock when running the signal handlers */
-        xfconf_cache_mutex_unlock(&cache->cache_lock);
+        xfconf_cache_mutex_unlock(cache);
         g_signal_emit(G_OBJECT(cache), signals[SIG_PROPERTY_CHANGED],
                       g_quark_from_string(old_item->property),
                       cache->channel_name, old_item->property,
                       item ? item->value : &empty_val);
-        xfconf_cache_mutex_lock(&cache->cache_lock);
+        xfconf_cache_mutex_lock(cache);
     }
 
     /* we handled the call, so set it to %NULL */
@@ -561,7 +577,7 @@
     if(old_item)
         xfconf_cache_old_item_free(old_item);
 out:
-    xfconf_cache_mutex_unlock(&cache->cache_lock);
+    xfconf_cache_mutex_unlock(cache);
 }
 
 
@@ -576,7 +592,7 @@
     XfconfCacheOldItem *old_item;
     GError *error = NULL;
 
-    xfconf_cache_mutex_lock(&cache->cache_lock);
+    xfconf_cache_mutex_lock(cache);
 
     old_item = g_hash_table_lookup(cache->pending_calls, call);
     if(G_UNLIKELY(!old_item)) {
@@ -594,7 +610,7 @@
     if(old_item)
         g_hash_table_remove(cache->pending_calls, old_item->call);
 
-    xfconf_cache_mutex_unlock(&cache->cache_lock);
+    xfconf_cache_mutex_unlock(cache);
 }
 #endif
 
@@ -634,7 +650,7 @@
 
     g_return_val_if_fail(g_tree_nnodes(cache->properties) == 0, FALSE);
 
-    xfconf_cache_mutex_lock(&cache->cache_lock);
+    xfconf_cache_mutex_lock(cache);
 
     if(xfconf_client_get_all_properties(proxy, cache->channel_name,
                                         property_base ? property_base : "/",
@@ -647,7 +663,7 @@
     } else
         g_propagate_error(error, tmp_error);
 
-    xfconf_cache_mutex_unlock(&cache->cache_lock);
+    xfconf_cache_mutex_unlock(cache);
 
     return ret;
 }
@@ -710,9 +726,9 @@
     g_return_val_if_fail(XFCONF_IS_CACHE(cache) && property
                          && (!error || !*error), FALSE);
 
-    xfconf_cache_mutex_lock(&cache->cache_lock);
+    xfconf_cache_mutex_lock(cache);
     ret = xfconf_cache_lookup_locked(cache, property, value, error);
-    xfconf_cache_mutex_unlock(&cache->cache_lock);
+    xfconf_cache_mutex_unlock(cache);
 
     return ret;
 }
@@ -727,7 +743,7 @@
     XfconfCacheItem *item = NULL;
     XfconfCacheOldItem *old_item = NULL;
 
-    xfconf_cache_mutex_lock(&cache->cache_lock);
+    xfconf_cache_mutex_lock(cache);
 
     item = g_tree_lookup(cache->properties, property);
     if(!item) {
@@ -756,7 +772,7 @@
             {
                 /* this is bad... */
                 g_propagate_error(error, tmp_error);
-                xfconf_cache_mutex_unlock(&cache->cache_lock);
+                xfconf_cache_mutex_unlock(cache);
                 return FALSE;
             }
 
@@ -771,7 +787,7 @@
     if(item) {
         /* if the value isn't changing, there's no reason to continue */
         if(_xfconf_gvalue_is_equal(item->value, value)) {
-            xfconf_cache_mutex_unlock(&cache->cache_lock);
+            xfconf_cache_mutex_unlock(cache);
             return TRUE;
         }
     }
@@ -814,7 +830,7 @@
         g_tree_insert(cache->properties, g_strdup(property), item);
     }
 
-    xfconf_cache_mutex_unlock(&cache->cache_lock);
+    xfconf_cache_mutex_unlock(cache);
 
     g_signal_emit(G_OBJECT(cache), signals[SIG_PROPERTY_CHANGED], 0,
                   cache->channel_name, property, value);
@@ -855,7 +871,7 @@
     XfconfCacheOldItem *old_item = NULL;
 #endif
 
-    xfconf_cache_mutex_lock(&cache->cache_lock);
+    xfconf_cache_mutex_lock(cache);
 
 #if 0
     /* it's not really feasible here to look up all the old/new values
@@ -919,7 +935,7 @@
     }
 #endif
 
-    xfconf_cache_mutex_unlock(&cache->cache_lock);
+    xfconf_cache_mutex_unlock(cache);
 
     return ret;
 }
@@ -929,10 +945,10 @@
 xfconf_cache_set_max_entries(XfconfCache *cache,
                              gint max_entries)
 {
-    xfconf_cache_mutex_lock(&cache->cache_lock);
+    xfconf_cache_mutex_lock(cache);
     cache->max_entries = max_entries;
     /* TODO: check tree for eviction */
-    xfconf_cache_mutex_unlock(&cache->cache_lock);
+    xfconf_cache_mutex_unlock(cache);
 }
 
 gint
@@ -945,10 +961,10 @@
 xfconf_cache_set_max_age(XfconfCache *cache,
                          gint max_age)
 {
-    xfconf_cache_mutex_lock(&cache->cache_lock);
+    xfconf_cache_mutex_lock(cache);
     cache->max_age = max_age;
     /* TODO: check tree for eviction */
-    xfconf_cache_mutex_unlock(&cache->cache_lock);
+    xfconf_cache_mutex_unlock(cache);
 }
 
 gint
