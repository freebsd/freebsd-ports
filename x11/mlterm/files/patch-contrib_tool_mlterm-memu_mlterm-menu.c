--- contrib/tool/mlterm-menu/mlterm-menu.c.orig	2008-08-06 08:21:01.000000000 +0400
+++ contrib/tool/mlterm-menu/mlterm-menu.c	2008-08-06 08:30:00.000000000 +0400
@@ -201,6 +201,7 @@
     GtkWidget* item;
     char* pty_list;
     char* name;
+    gchar *utf8_name;
     char* pty;
     char* command;
     int is_active;
@@ -228,11 +229,12 @@
             name = pty;
         if (strncmp(name, "/dev/", 5) == 0)
             name += 5;
+	utf8_name = g_locale_to_utf8(name, -1, NULL, NULL, NULL);
 
         command = malloc(strlen(pty) + 12);
         sprintf(command, "select_pty=%s", pty);
 
-        item = gtk_radio_menu_item_new_with_label(group, name);
+        item = gtk_radio_menu_item_new_with_label(group, utf8_name);
         group = gtk_radio_menu_item_group(GTK_RADIO_MENU_ITEM(item));
 
         gtk_signal_connect(GTK_OBJECT(item), "toggled",
@@ -240,6 +242,7 @@
                            (gpointer) command);
 
         gtk_menu_append(menu, item);
+	g_free(utf8_name);
         if (is_active) {
             gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(item),
                                            TRUE);
