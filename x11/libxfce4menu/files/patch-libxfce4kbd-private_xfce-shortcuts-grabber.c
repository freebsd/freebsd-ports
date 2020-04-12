--- libxfce4kbd-private/xfce-shortcuts-grabber.c.orig	2020-04-08 15:05:21 UTC
+++ libxfce4kbd-private/xfce-shortcuts-grabber.c
@@ -74,6 +74,16 @@ struct _XfceKey
 {
   guint keyval;
   guint modifiers;
+  /*
+   * Cache of old keycodes grabbed by this key.  Used to ungrab the keycodes we
+   * actually grabbed.
+   *
+   * An arbitrary number of keys may generate the same keyval.  Rather than add
+   * memory allocation to this path, I just constrained the unmapping behavior
+   * to 8 identically coded keys.  It seems unlikely?  But I am no xkeyboard
+   * expert.
+   */
+  int keycodes[8];
 };
 
 
@@ -269,12 +279,20 @@ xfce_shortcuts_grabber_grab (XfceShortcutsGrabber *gra
     }
 
   /* Get all keys generating keyval */
-  if (!gdk_keymap_get_entries_for_keyval (keymap,key->keyval,
+  if (grab && !gdk_keymap_get_entries_for_keyval (keymap,key->keyval,
                                           &keys, &n_keys))
     {
       TRACE ("Got no keys for keyval");
       return;
     }
+  if (grab)
+    {
+      if (n_keys > G_N_ELEMENTS(key->keycodes))
+        TRACE ("Got %d keys for keyval but can remember only %d", n_keys,
+          (int)G_N_ELEMENTS(key->keycodes));
+    }
+  else
+    n_keys = G_N_ELEMENTS(key->keycodes);
 
   if (n_keys == 0)
     {
@@ -290,9 +308,9 @@ xfce_shortcuts_grabber_grab (XfceShortcutsGrabber *gra
   for (i = 0; i < n_keys; i ++)
     {
       /* Grab all hardware keys generating keyval */
+      if (grab)
+        TRACE ("New Keycode: %d", keys[i].keycode);
 
-      TRACE ("Keycode: %d", keys[i].keycode);
-
       for (j = 0; j < screens; j++)
         {
           /* Do the grab on all screens */
@@ -338,11 +356,14 @@ xfce_shortcuts_grabber_grab (XfceShortcutsGrabber *gra
                           False,
                           GrabModeAsync,
                           GrabModeAsync);
-              else
+              else {
+                if (key->keycodes[i] == -1)
+                  break;
                 XUngrabKey (GDK_DISPLAY_XDISPLAY (display),
-                            keys[i].keycode,
+                            key->keycodes[i],
                             modifiers | mod_masks [k],
                             root_window);
+              }
             }
 
           gdk_flush ();
@@ -355,9 +376,18 @@ xfce_shortcuts_grabber_grab (XfceShortcutsGrabber *gra
                 TRACE ("Failed to ungrab");
             }
         }
+      /* Remember the old keycode, as we need it to ungrab. */
+      if (grab && i < G_N_ELEMENTS (key->keycodes))
+        key->keycodes[i] = keys[i].keycode;
+      else if (!grab)
+        key->keycodes[i] = -1;
     }
 
-  g_free (keys);
+  if (grab) {
+    g_free (keys);
+    for (; i < G_N_ELEMENTS (key->keycodes); i++)
+      key->keycodes[i] = -1;
+  }
 }
 
 
@@ -514,6 +544,8 @@ xfce_shortcuts_grabber_add (XfceShortcutsGrabber *grab
   g_return_if_fail (shortcut != NULL);
 
   key = g_new0 (XfceKey, 1);
+  for (size_t i = 0; i < G_N_ELEMENTS (key->keycodes); i++)
+    key->keycodes[i] = -1;
 
   gtk_accelerator_parse (shortcut, &key->keyval, &key->modifiers);
 
