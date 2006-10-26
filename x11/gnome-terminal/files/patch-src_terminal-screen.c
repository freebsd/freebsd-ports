--- src/terminal-screen.c.orig	Wed Oct 18 15:50:28 2006
+++ src/terminal-screen.c	Wed Oct 18 15:49:42 2006
@@ -244,6 +244,10 @@
       GtkAllocation *allocation)
 {
   GtkWidget *child;
+  GtkAllocation old_allocation;
+
+  old_allocation.width = widget->allocation.width;
+  old_allocation.height = widget->allocation.height;
 
   widget->allocation = *allocation;
 
@@ -251,6 +255,13 @@
   g_assert (child != NULL);
 
   gtk_widget_size_allocate (child, allocation);
+
+  if (old_allocation.width != allocation->width ||
+      old_allocation.height != allocation->height)
+    {
+      GtkWidget *term = TERMINAL_SCREEN (widget)->priv->term;
+      gtk_widget_queue_resize_no_redraw (term);
+    }
 }
 
 static void
@@ -278,22 +289,22 @@
 #define URLPATH   "/[" PATHCHARS "]*[^]'.}>) \t\r\n,\\\"]"
 
   terminal_widget_match_add (screen->priv->term,
-			     "\\<" SCHEME "//(" USER "@)?[" HOSTCHARS ".]+"
-			     "(:[0-9]+)?(" URLPATH ")?\\>/?", FLAVOR_AS_IS);
+			     "[[:<:]]" SCHEME "//(" USER "@)?[" HOSTCHARS ".]+"
+			     "(:[0-9]+)?(" URLPATH ")?[[:>:]]/?", FLAVOR_AS_IS);
 
   terminal_widget_match_add (screen->priv->term,
-			     "\\<(www|ftp)[" HOSTCHARS "]*\\.[" HOSTCHARS ".]+"
-			     "(:[0-9]+)?(" URLPATH ")?\\>/?",
+			     "[[:<:]](www|ftp)[" HOSTCHARS "]*\\.[" HOSTCHARS ".]+"
+			     "(:[0-9]+)?(" URLPATH ")?[[:>:]]/?",
 			     FLAVOR_DEFAULT_TO_HTTP);
 
   terminal_widget_match_add (screen->priv->term,
-			     "\\<(mailto:)?[a-z0-9][a-z0-9.-]*@[a-z0-9]"
-			     "[a-z0-9-]*(\\.[a-z0-9][a-z0-9-]*)+\\>",
+			     "[[:<:]](mailto:)?[a-z0-9][a-z0-9.-]*@[a-z0-9]"
+			     "[a-z0-9-]*(\\.[a-z0-9][a-z0-9-]*)+[[:>:]]",
 			     FLAVOR_EMAIL);
 
   terminal_widget_match_add (screen->priv->term,
-			     "\\<news:[-A-Z\\^_a-z{|}~!\"#$%&'()*+,./0-9;:=?`]+"
-			     "@[" HOSTCHARS ".]+(:[0-9]+)?\\>", FLAVOR_AS_IS);
+			     "[[:<:]]news:[-A-Z\\^_a-z{|}~!\"#$%&'()*+,./0-9;:=?`]+"
+			     "@[" HOSTCHARS ".]+(:[0-9]+)?[[:>:]]", FLAVOR_AS_IS);
 
   terminal_screen_setup_dnd (screen);
 
@@ -548,7 +559,6 @@
        */
       terminal_screen_update_scrollbar (screen);
       terminal_window_update_icon (screen->priv->window);
-      terminal_window_update_geometry (screen->priv->window);
     }
   
   if (GTK_WIDGET_REALIZED (screen->priv->term))
@@ -909,7 +919,6 @@
   
   terminal_widget_set_allow_bold (term,
                                   terminal_profile_get_allow_bold (profile));
-  terminal_window_set_size (screen->priv->window, screen, TRUE);
 }
 
 static void
@@ -1019,6 +1028,7 @@
 GtkWidget*
 terminal_screen_get_widget (TerminalScreen *screen)
 {
+  if (screen == NULL) return NULL;
   return screen->priv->term;
 }
 
