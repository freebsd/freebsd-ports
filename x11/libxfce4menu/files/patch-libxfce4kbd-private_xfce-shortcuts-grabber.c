--- libxfce4kbd-private/xfce-shortcuts-grabber.c.orig	2019-08-11 16:02:06 UTC
+++ libxfce4kbd-private/xfce-shortcuts-grabber.c
@@ -72,8 +72,9 @@ struct _XfceShortcutsGrabberPrivate
 
 struct _XfceKey
 {
-  guint keyval;
-  guint modifiers;
+  guint   keyval;
+  guint   modifiers;
+  GArray *keycodes;
 };
 
 
@@ -339,10 +340,14 @@ xfce_shortcuts_grabber_grab (XfceShortcutsGrabber *gra
                           GrabModeAsync,
                           GrabModeAsync);
               else
-                XUngrabKey (GDK_DISPLAY_XDISPLAY (display),
-                            keys[i].keycode,
-                            modifiers | mod_masks [k],
-                            root_window);
+                {
+                  if (i >= key->keycodes->len)
+                    break;
+                  XUngrabKey (GDK_DISPLAY_XDISPLAY (display),
+                              g_array_index (key->keycodes, guint, i),
+                              modifiers | mod_masks [k],
+                              root_window);
+                }
             }
 
           gdk_flush ();
@@ -355,8 +360,20 @@ xfce_shortcuts_grabber_grab (XfceShortcutsGrabber *gra
                 TRACE ("Failed to ungrab");
             }
         }
+      /* Remember the old keycode, as we need it to ungrab. */
+      if (grab)
+        g_array_append_val (key->keycodes, keys[i].keycode);
+      else
+        g_array_index(key->keycodes, guint, i) = UINT_MAX;
     }
 
+  /* Cleanup elements containing UINT_MAX from the key->keycodes array */
+  for (i = key->keycodes->len - 1; i >= 0; i --)
+    {
+      if (g_array_index(key->keycodes, guint, i) == UINT_MAX)
+        g_array_remove_index_fast(key->keycodes, i);
+    }
+
   g_free (keys);
 }
 
@@ -514,6 +531,7 @@ xfce_shortcuts_grabber_add (XfceShortcutsGrabber *grab
   g_return_if_fail (shortcut != NULL);
 
   key = g_new0 (XfceKey, 1);
+  key->keycodes = g_array_new (FALSE, TRUE, sizeof (guint));
 
   gtk_accelerator_parse (shortcut, &key->keyval, &key->modifiers);
 
@@ -523,7 +541,10 @@ xfce_shortcuts_grabber_add (XfceShortcutsGrabber *grab
       g_hash_table_insert (grabber->priv->keys, g_strdup (shortcut), key);
     }
   else
-    g_free (key);
+    {
+      g_array_free (key->keycodes, TRUE);
+      g_free (key);
+    }
 }
 
 
