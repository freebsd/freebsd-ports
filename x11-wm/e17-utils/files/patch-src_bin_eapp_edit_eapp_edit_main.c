--- src/bin/eapp_edit/eapp_edit_main.c.orig	Thu Sep  7 22:16:56 2006
+++ src/bin/eapp_edit/eapp_edit_main.c	Thu Sep  7 22:20:34 2006
@@ -420,13 +420,11 @@
     e = ev;
     if (e->response == EWL_STOCK_OK)
     {
-        char *icon;
         const char *icon2;
         char icon3[PATH_MAX];
     
-        icon = ewl_filedialog_selected_file_get(EWL_FILEDIALOG(w));
-        icon2 = ewl_filedialog_directory_get(EWL_FILEDIALOG(w));
-        snprintf(icon3, PATH_MAX, "%s/%s", icon2, icon);
+	icon2 = ewl_filedialog_file_get(EWL_FILEDIALOG(w));
+        snprintf(icon3, PATH_MAX, "%s", icon2);
 
         o = ewl_widget_name_find("icon");
         ewl_widget_data_set(o, "file", strdup(icon3));
