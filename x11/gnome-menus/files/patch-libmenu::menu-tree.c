--- libmenu/menu-tree.c.orig	Tue Mar 22 05:34:24 2005
+++ libmenu/menu-tree.c	Wed Mar 23 14:34:04 2005
@@ -67,6 +67,12 @@
   gpointer            user_data;
 } MenuTreeMonitor;
 
+typedef struct
+{
+  MenuTreeDirectory *directory;
+  GSList            *list;
+} MenuTreeListifyForeachData;
+
 struct MenuTreeDirectory
 {
   MenuTreeDirectory *parent;
@@ -75,6 +81,7 @@
   char         *name;
 
   GSList *entries;
+  GSList *excluded_entries;
   GSList *subdirs;
 
   guint refcount : 24;
@@ -747,17 +754,15 @@
     }
 }
 
-GSList *
-menu_tree_directory_get_entries (MenuTreeDirectory *directory)
+static GSList *
+copy_and_ref_entry_list (GSList *list)
 {
   GSList *retval;
   GSList *tmp;
 
-  g_return_val_if_fail (directory != NULL, NULL);
-
   retval = NULL;
 
-  tmp = directory->entries;
+  tmp = list;
   while (tmp != NULL)
     {
       retval = g_slist_prepend (retval,
@@ -770,6 +775,22 @@
 }
 
 GSList *
+menu_tree_directory_get_entries (MenuTreeDirectory *directory)
+{
+  g_return_val_if_fail (directory != NULL, NULL);
+
+  return copy_and_ref_entry_list (directory->entries);
+}
+
+GSList *
+menu_tree_directory_get_excluded_entries (MenuTreeDirectory *directory)
+{
+  g_return_val_if_fail (directory != NULL, NULL);
+
+  return copy_and_ref_entry_list (directory->excluded_entries);
+}
+
+GSList *
 menu_tree_directory_get_subdirs (MenuTreeDirectory *directory)
 {
   GSList *retval;
@@ -936,6 +957,7 @@
   retval->name             = g_strdup (name);
   retval->directory_entry  = NULL;
   retval->entries          = NULL;
+  retval->excluded_entries = NULL;
   retval->subdirs          = NULL;
   retval->only_unallocated = FALSE;
   retval->refcount         = 1;
@@ -2488,16 +2510,21 @@
 }
 
 static void
-entries_listify_foreach (const char        *desktop_file_id,
-                         DesktopEntry      *desktop_entry,
-                         MenuTreeDirectory *directory)
+entries_listify_foreach (const char                 *desktop_file_id,
+                         DesktopEntry               *desktop_entry,
+                         MenuTreeListifyForeachData *foreach_data)
 {
   MenuTreeEntry *entry;
 
-  entry = menu_tree_entry_new (directory, desktop_entry, desktop_file_id);
+  g_return_if_fail (foreach_data);
+  g_return_if_fail (foreach_data->directory);
+
+  entry = menu_tree_entry_new (foreach_data->directory,
+		  	       desktop_entry,
+			       desktop_file_id);
 
-  directory->entries = g_slist_prepend (directory->entries,
-                                        entry);
+  foreach_data->list = g_slist_prepend (foreach_data->list,
+		  			entry);
 }
 
 static MenuTreeDirectory *
@@ -2511,11 +2538,14 @@
   MenuLayoutNode     *layout_iter;
   MenuTreeDirectory  *directory;
   DesktopEntrySet    *entries;
+  DesktopEntrySet    *excluded_entries;
   gboolean            deleted;
   DesktopEntrySet    *allocated_set;
   gboolean            only_unallocated;
   GSList             *tmp;
 
+  MenuTreeListifyForeachData foreach_data;
+
   g_assert (menu_layout_node_get_type (layout) == MENU_LAYOUT_NODE_MENU);
   g_assert (menu_layout_node_menu_get_name (layout) != NULL);
 
@@ -2532,6 +2562,7 @@
   dir_dirs = menu_layout_node_menu_get_directory_dirs (layout);
 
   entries = desktop_entry_set_new ();
+  excluded_entries = desktop_entry_set_new ();
   allocated_set = desktop_entry_set_new ();
 
   layout_iter = menu_layout_node_get_children (layout);
@@ -2578,6 +2609,7 @@
                 if (rule_set != NULL)
                   {
                     desktop_entry_set_union (entries, rule_set);
+                    desktop_entry_set_subtract (excluded_entries, rule_set);
                     desktop_entry_set_union (allocated_set, rule_set);
                     desktop_entry_set_unref (rule_set);
                   }
@@ -2610,6 +2642,7 @@
                 if (rule_set != NULL)
                   {
                     desktop_entry_set_subtract (entries, rule_set);
+                    desktop_entry_set_union (excluded_entries, rule_set);
                     desktop_entry_set_unref (rule_set);
                   }
 
@@ -2707,15 +2740,28 @@
   if (deleted)
     {
       desktop_entry_set_unref (entries);
+      desktop_entry_set_unref (excluded_entries);
       menu_tree_directory_unref (directory);
       return NULL;
     }
 
-  directory->entries = NULL;
+  foreach_data.directory = directory;
+  foreach_data.list = NULL;
   desktop_entry_set_foreach (entries,
                              (DesktopEntrySetForeachFunc) entries_listify_foreach,
-                             directory);
+                             &foreach_data);
   desktop_entry_set_unref (entries);
+
+  directory->entries = foreach_data.list;
+
+  foreach_data.directory = directory;
+  foreach_data.list = NULL;
+  desktop_entry_set_foreach (excluded_entries,
+		  	     (DesktopEntrySetForeachFunc) entries_listify_foreach,
+			     &foreach_data);
+  desktop_entry_set_unref (excluded_entries);
+
+  directory->excluded_entries = foreach_data.list;
 
   tmp = directory->entries;
   while (tmp != NULL)
