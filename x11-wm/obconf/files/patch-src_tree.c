--- src/tree.c.orig	2026-06-08 11:58:29 UTC
+++ src/tree.c
@@ -88,7 +88,7 @@ void tree_apply()
 void tree_apply()
 {
     gchar *p, *d;
-    gboolean err;
+    gboolean err = FALSE;
 
     if (obc_config_file)
         p = g_strdup(obc_config_file);
@@ -102,6 +102,8 @@ void tree_apply()
 
     if (!obt_xml_save_file(parse_i, p, TRUE)) {
         gchar *s;
+
+        err = TRUE;
         s = g_strdup_printf("An error occured while saving the "
                             "config file '%s'", p);
         obconf_error(s, FALSE);
