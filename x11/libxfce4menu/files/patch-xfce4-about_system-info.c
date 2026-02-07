--- xfce4-about/system-info.c.orig	2024-10-19 08:20:00 UTC
+++ xfce4-about/system-info.c
@@ -662,8 +662,9 @@ get_os_name (void)
 get_os_name (void)
 {
   GHashTable *os_info;
-  gchar *name, *version_id, *pretty_name, *build_id;
+  gchar *name, *version_id, *build_id;
   gchar *result = NULL;
+  gchar *kernel_version = NULL;
   g_autofree gchar *name_version = NULL;
 
   os_info = get_os_info ();
@@ -677,13 +678,13 @@ get_os_name (void)
 
   name = g_hash_table_lookup (os_info, "NAME");
   version_id = g_hash_table_lookup (os_info, "VERSION_ID");
-  pretty_name = g_hash_table_lookup (os_info, "PRETTY_NAME");
   build_id = g_hash_table_lookup (os_info, "BUILD_ID");
 
-  if (pretty_name)
-    name_version = g_strdup (pretty_name);
-  else if (name && version_id)
-    name_version = g_strdup_printf ("%s %s", name, version_id);
+  /* Don't use PRETTY_NAME value because sometimes mismatch with uname -r */
+  kernel_version = get_system_info (KERNEL);
+
+  if (name && kernel_version)
+    name_version = g_strdup_printf ("%s %s", name, kernel_version);
   else
     name_version = g_strdup (_("Unknown"));
 
