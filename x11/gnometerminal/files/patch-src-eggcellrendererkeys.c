--- src/eggcellrendererkeys.c.orig	Thu Jul 29 23:34:48 2004
+++ src/eggcellrendererkeys.c	Thu Jul 29 23:35:36 2004
@@ -584,7 +584,7 @@
 void
 egg_cell_renderer_keys_set_accelerator (EggCellRendererKeys *keys,
                                         guint                keyval,
-                                        GdkModifierType      mask)
+                                        EggVirtualModifierType mask)
 {
   char *text;
   gboolean changed;
@@ -626,7 +626,7 @@
 void
 egg_cell_renderer_keys_get_accelerator (EggCellRendererKeys *keys,
                                         guint               *keyval,
-                                        GdkModifierType     *mask)
+                                        EggVirtualModifierType *mask)
 {
   g_return_if_fail (EGG_IS_CELL_RENDERER_KEYS (keys));
 
