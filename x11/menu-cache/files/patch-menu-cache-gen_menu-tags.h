--- menu-cache-gen/menu-tags.h.orig	2020-08-22 16:05:24 UTC
+++ menu-cache-gen/menu-tags.h
@@ -22,38 +22,38 @@
 #include <libfm/fm-extra.h>
 #include <menu-cache.h>
 
-FmXmlFileTag menuTag_Menu;
-FmXmlFileTag menuTag_AppDir;
-FmXmlFileTag menuTag_DefaultAppDirs;
-FmXmlFileTag menuTag_DirectoryDir;
-FmXmlFileTag menuTag_DefaultDirectoryDirs;
-FmXmlFileTag menuTag_Include;
-FmXmlFileTag menuTag_Exclude;
-FmXmlFileTag menuTag_Filename;
-FmXmlFileTag menuTag_Or;
-FmXmlFileTag menuTag_And;
-FmXmlFileTag menuTag_Not;
-FmXmlFileTag menuTag_Category;
-FmXmlFileTag menuTag_MergeFile;
-FmXmlFileTag menuTag_MergeDir;
-FmXmlFileTag menuTag_DefaultMergeDirs;
-FmXmlFileTag menuTag_Directory;
-FmXmlFileTag menuTag_Name;
-FmXmlFileTag menuTag_Deleted;
-FmXmlFileTag menuTag_NotDeleted;
-FmXmlFileTag menuTag_OnlyUnallocated;
-FmXmlFileTag menuTag_NotOnlyUnallocated;
-FmXmlFileTag menuTag_All;
-FmXmlFileTag menuTag_LegacyDir;
-FmXmlFileTag menuTag_KDELegacyDirs;
-FmXmlFileTag menuTag_Move;
-FmXmlFileTag menuTag_Old;
-FmXmlFileTag menuTag_New;
-FmXmlFileTag menuTag_Layout;
-FmXmlFileTag menuTag_DefaultLayout;
-FmXmlFileTag menuTag_Menuname;
-FmXmlFileTag menuTag_Separator;
-FmXmlFileTag menuTag_Merge;
+extern FmXmlFileTag menuTag_Menu;
+extern FmXmlFileTag menuTag_AppDir;
+extern FmXmlFileTag menuTag_DefaultAppDirs;
+extern FmXmlFileTag menuTag_DirectoryDir;
+extern FmXmlFileTag menuTag_DefaultDirectoryDirs;
+extern FmXmlFileTag menuTag_Include;
+extern FmXmlFileTag menuTag_Exclude;
+extern FmXmlFileTag menuTag_Filename;
+extern FmXmlFileTag menuTag_Or;
+extern FmXmlFileTag menuTag_And;
+extern FmXmlFileTag menuTag_Not;
+extern FmXmlFileTag menuTag_Category;
+extern FmXmlFileTag menuTag_MergeFile;
+extern FmXmlFileTag menuTag_MergeDir;
+extern FmXmlFileTag menuTag_DefaultMergeDirs;
+extern FmXmlFileTag menuTag_Directory;
+extern FmXmlFileTag menuTag_Name;
+extern FmXmlFileTag menuTag_Deleted;
+extern FmXmlFileTag menuTag_NotDeleted;
+extern FmXmlFileTag menuTag_OnlyUnallocated;
+extern FmXmlFileTag menuTag_NotOnlyUnallocated;
+extern FmXmlFileTag menuTag_All;
+extern FmXmlFileTag menuTag_LegacyDir;
+extern FmXmlFileTag menuTag_KDELegacyDirs;
+extern FmXmlFileTag menuTag_Move;
+extern FmXmlFileTag menuTag_Old;
+extern FmXmlFileTag menuTag_New;
+extern FmXmlFileTag menuTag_Layout;
+extern FmXmlFileTag menuTag_DefaultLayout;
+extern FmXmlFileTag menuTag_Menuname;
+extern FmXmlFileTag menuTag_Separator;
+extern FmXmlFileTag menuTag_Merge;
 
 typedef enum {
     MERGE_NONE, /* starting value */
@@ -152,19 +152,19 @@ typedef struct {
 } MenuRule;
 
 /* requested language(s) */
-char **languages;
+extern char **languages;
 
 /* list of menu files to monitor */
-GSList *MenuFiles;
+extern GSList *MenuFiles;
 
 /* list of menu dirs to monitor */
-GSList *MenuDirs;
+extern GSList *MenuDirs;
 
 /* list of available app dirs */
-GSList *AppDirs;
+extern GSList *AppDirs;
 
 /* list of available dir dirs */
-GSList *DirDirs;
+extern GSList *DirDirs;
 
 /* parse and merge menu files */
 MenuMenu *get_merged_menu(const char *file, FmXmlFile **xmlfile, GError **error);
@@ -177,7 +177,7 @@ gboolean save_menu_cache(MenuMenu *layout, const char 
 void _free_layout_items(GList *data);
 
 /* verbosity level */
-gint verbose;
+extern gint verbose;
 
 #define DBG if (verbose) g_debug
 #define VDBG if (verbose > 1) g_debug
