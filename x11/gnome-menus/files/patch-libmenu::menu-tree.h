--- libmenu/menu-tree.h.orig	Wed Jan 12 15:23:52 2005
+++ libmenu/menu-tree.h	Tue Mar  1 01:24:17 2005
@@ -44,8 +44,9 @@
 MenuTreeDirectory *menu_tree_get_directory_from_path (MenuTree   *tree,
 						      const char *path);
 
-GSList *menu_tree_directory_get_entries (MenuTreeDirectory *directory);
-GSList *menu_tree_directory_get_subdirs (MenuTreeDirectory *directory);
+GSList *menu_tree_directory_get_entries          (MenuTreeDirectory *directory);
+GSList *menu_tree_directory_get_excluded_entries (MenuTreeDirectory *directory);
+GSList *menu_tree_directory_get_subdirs          (MenuTreeDirectory *directory);
 
 MenuTreeDirectory *menu_tree_directory_ref   (MenuTreeDirectory *directory);
 void               menu_tree_directory_unref (MenuTreeDirectory *directory);
