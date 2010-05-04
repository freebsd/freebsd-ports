--- src/evilvte.c.orig	2010-04-06 07:35:41.000000000 +0200
+++ src/evilvte.c	2010-04-23 02:01:06.000000000 +0200
@@ -930,7 +930,6 @@
 #endif
 #if WINDOW_TITLE_DYNAMIC
   gtk_window_set_title(GTK_WINDOW(main_window), vte_terminal_get_window_title(VTE_TERMINAL(term->vte)));
-  gtk_window_set_icon_name(GTK_WINDOW(main_window), vte_terminal_get_icon_title(VTE_TERMINAL(term->vte)));
 #endif
 }
 #endif
@@ -939,7 +938,7 @@
 int menu_popup(GtkWidget *widget, GdkEventButton *event)
 {
 #ifdef MATCH_STRING_EXEC
-  if (event->button == 1) {
+  if (event->button == 2) {
     int tag = -1;
 #if TAB
     current_tab = gtk_notebook_get_nth_page(GTK_NOTEBOOK(notebook), gtk_notebook_get_current_page(GTK_NOTEBOOK(notebook)));
@@ -948,11 +947,12 @@
     matched_url = vte_terminal_match_check(VTE_TERMINAL(term->vte), event->x / vte_terminal_get_char_width(VTE_TERMINAL(term->vte)), event->y / vte_terminal_get_char_height(VTE_TERMINAL(term->vte)), &tag);
     if (matched_url != NULL) {
       char new_window_str[256];
-      g_snprintf(new_window_str, sizeof(new_window_str), "%s %s &", MATCH_STRING_EXEC, matched_url);
+      g_snprintf(new_window_str, sizeof(new_window_str), "%s '%s' &", MATCH_STRING_EXEC, matched_url);
       system(new_window_str);
       matched_url = NULL;
+      return TRUE;
     }
-    return TRUE;
+    return FALSE;
   }
 #endif
 
@@ -2318,7 +2318,7 @@
 void do_match_open()
 {
   char new_window_str[256];
-  g_snprintf(new_window_str, sizeof(new_window_str), "%s %s &", MENU_MATCH_STRING_EXEC, matched_url);
+  g_snprintf(new_window_str, sizeof(new_window_str), "%s '%s' &", MENU_MATCH_STRING_EXEC, matched_url);
   system(new_window_str);
   matched_url = NULL;
 }
@@ -2699,7 +2699,6 @@
 #endif
 #if WINDOW_TITLE_DYNAMIC
   gtk_window_set_title(GTK_WINDOW(main_window), vte_terminal_get_window_title(VTE_TERMINAL(term->vte)));
-  gtk_window_set_icon_name(GTK_WINDOW(main_window), vte_terminal_get_icon_title(VTE_TERMINAL(term->vte)));
 #endif
 }
 
