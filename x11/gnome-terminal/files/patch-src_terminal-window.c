--- src/terminal-window.c.orig	Fri Sep  1 01:34:03 2006
+++ src/terminal-window.c	Wed Oct 18 15:32:15 2006
@@ -157,6 +157,9 @@
                                            const char      *dir);
 static void new_window_callback           (GtkWidget      *menuitem,
                                            TerminalWindow *window);
+static void size_request_callback         (GtkWidget      *widget,
+                                           GtkRequisition *requisition,
+                                           TerminalWindow *window);
 static void new_tab_callback              (GtkWidget      *menuitem,
                                            TerminalWindow *window);
 static gboolean key_press_callback	  (GtkWidget      *widget,
@@ -237,6 +240,8 @@
 
 static void terminal_window_show (GtkWidget *widget);
 
+static void update_geometry  (TerminalWindow *window);
+
 static gboolean confirm_close_window (TerminalWindow *window);
 
 static gpointer parent_class;
@@ -871,7 +876,12 @@
   gtk_box_pack_end (GTK_BOX (window->priv->main_vbox),
                     window->priv->notebook,
                     TRUE, TRUE, 0);  
-  
+
+  g_signal_connect (G_OBJECT (window->priv->main_vbox),
+                    "size_request",
+                    G_CALLBACK (size_request_callback),
+                    window);
+
   mi = append_menuitem (window->priv->menubar,
                         "", NULL,
                         NULL, NULL);
@@ -1506,14 +1516,6 @@
       gtk_widget_hide (window->priv->menubar);
     }
   reset_menubar_labels (window);
-
-  if (window->priv->active_term)
-    {
-#ifdef DEBUG_GEOMETRY
-      g_fprintf (stderr,"setting size after toggling menubar visibility\n");
-#endif
-      terminal_window_set_size (window, window->priv->active_term, TRUE);
-    }
 }
 
 gboolean
@@ -1531,98 +1533,21 @@
 }
 
 void
-terminal_window_set_size (TerminalWindow *window,
-                          TerminalScreen *screen,
-                          gboolean        even_if_mapped)
-{
-  terminal_window_set_size_force_grid (window, screen, even_if_mapped, -1, -1);
-}
-
-void
-terminal_window_set_size_force_grid (TerminalWindow *window,
-                                     TerminalScreen *screen,
-                                     gboolean        even_if_mapped,
-                                     int             force_grid_width,
-                                     int             force_grid_height)
-{
-  /* Owen's hack from gnome-terminal */
-  GtkWidget *widget;
-  GtkWidget *app;
-  GtkRequisition toplevel_request;
-  GtkRequisition widget_request;
-  int w, h;
-  int char_width;
-  int char_height;
-  int grid_width;
-  int grid_height;
-  int xpad;
-  int ypad;
-
-  /* be sure our geometry is up-to-date */
-  terminal_window_update_geometry (window);
-  widget = terminal_screen_get_widget (screen);
-  
-  app = gtk_widget_get_toplevel (widget);
-  g_assert (app != NULL);
-
-  gtk_widget_size_request (app, &toplevel_request);
-  gtk_widget_size_request (widget, &widget_request);
-
-#ifdef DEBUG_GEOMETRY
-  g_fprintf (stderr,"set size: toplevel %dx%d widget %dx%d\n",
-           toplevel_request.width, toplevel_request.height,
-           widget_request.width, widget_request.height);
-#endif
-  
-  w = toplevel_request.width - widget_request.width;
-  h = toplevel_request.height - widget_request.height;
-
-  terminal_widget_get_cell_size (widget, &char_width, &char_height);
-  terminal_widget_get_size (widget, &grid_width, &grid_height);
-
-  if (force_grid_width >= 0)
-    grid_width = force_grid_width;
-  if (force_grid_height >= 0)
-    grid_height = force_grid_height;
-  
-  terminal_widget_get_padding (widget, &xpad, &ypad);
-  
-  w += xpad + char_width * grid_width;
-  h += ypad + char_height * grid_height;
-
-#ifdef DEBUG_GEOMETRY
-  g_fprintf (stderr,"set size: grid %dx%d force %dx%d setting %dx%d pixels\n",
-           grid_width, grid_height, force_grid_width, force_grid_height, w, h);
-#endif
-
-  if (even_if_mapped && GTK_WIDGET_MAPPED (app)) {
-    gtk_window_resize (GTK_WINDOW (app), w, h);
-  }
-  else {
-    gtk_window_set_default_size (GTK_WINDOW (app), w, h);
-  }
-}
-
-void
 terminal_window_set_active (TerminalWindow *window,
                             TerminalScreen *screen)
 {
-  GtkWidget *widget;
   TerminalProfile *profile;
+  GtkWidget *old_widget, *new_widget;
   
   if (window->priv->active_term == screen)
     return;
   
-  widget = terminal_screen_get_widget (screen);
-  
   profile = terminal_screen_get_profile (screen);
 
-  if (!GTK_WIDGET_REALIZED (widget))
-    gtk_widget_realize (widget); /* we need this for the char width */
-
+  old_widget = terminal_screen_get_widget (window->priv->active_term);
   window->priv->active_term = screen;
+  new_widget = terminal_screen_get_widget (window->priv->active_term);
 
-  terminal_window_update_geometry (window);
   terminal_window_update_icon (window);
   
   /* Override menubar setting if it wasn't restored from session */
@@ -1641,11 +1566,13 @@
                                  gtk_notebook_page_num (GTK_NOTEBOOK (window->priv->notebook),
                                                         GTK_WIDGET (screen)));
 
-  /* set size of window to current grid size */
-#ifdef DEBUG_GEOMETRY
-  g_fprintf (stderr,"setting size after flipping notebook pages\n");
-#endif
-  terminal_window_set_size (window, screen, TRUE);
+  /* Make sure that the widget is no longer hidden due to the workaround */
+  gtk_widget_show (new_widget);
+  /* Workaround to remove gtknotebook's feature of computing its size based on
+   * all pages. When the widget is hidden, its size will not be taken into
+   * account.
+   */
+  if (old_widget != NULL) gtk_widget_hide (old_widget);
   
   update_copy_sensitivity (window);
   
@@ -1704,18 +1631,12 @@
   GtkWidget* page_widget;
   TerminalScreen *screen;
   GtkWidget *menu_item;
-  int old_grid_width, old_grid_height;
-  GtkWidget *old_widget;
-  
-  old_widget = NULL;
-  old_grid_width = -1;
-  old_grid_height = -1;
+  GtkWidget *old_widget, *new_widget;
 
   if (window->priv->active_term == NULL)
     return;
 
   old_widget = terminal_screen_get_widget (window->priv->active_term);
-  terminal_widget_get_size (old_widget, &old_grid_width, &old_grid_height);
   
   page_widget = gtk_notebook_get_nth_page (GTK_NOTEBOOK (notebook),
                                            page_num);
@@ -1725,17 +1646,19 @@
   screen = TERMINAL_SCREEN (page_widget);
 
   g_assert (screen);
-
+  
   terminal_window_set_active (window, screen);
-
-  /* This is so we maintain the same grid moving among tabs with
-   * different fonts.
-   */
-#ifdef DEBUG_GEOMETRY
-  g_fprintf (stderr,"setting size in switch_page handler\n");
-#endif
-  terminal_window_set_size_force_grid (window, screen, TRUE, old_grid_width, old_grid_height);
   
+  new_widget = terminal_screen_get_widget (screen);
+
+  if (old_widget != new_widget) {
+    int old_grid_width, old_grid_height;
+    /* This is so that we maintain the same grid */
+    terminal_widget_get_size (old_widget, &old_grid_width, &old_grid_height);
+    terminal_widget_set_size (new_widget, old_grid_width, old_grid_height);
+    gtk_widget_queue_resize_no_redraw (new_widget);
+  }
+
   update_tab_sensitivity (window);
   
   menu_item = screen_get_menuitem (screen);
@@ -1836,7 +1759,6 @@
                                TerminalScreen  *screen,
                                TerminalWindow  *window)
 {  
-  gboolean single;
   /* Called from terminal_notebook_move_tab() */
   if (find_screen (window, screen) != NULL) {
     g_assert (terminal_screen_get_window (screen) == window);
@@ -1868,11 +1790,6 @@
   reset_tab_menuitems (window);
   update_tab_sensitivity (window);
 
-  /* The tab bar may have disappeared */
-  single = g_list_length (window->priv->terms) == 1;
-  if (single)
-    terminal_window_set_size (window, window->priv->active_term, TRUE);
-
   /* Close window if no more terminals */
   if (window->priv->terms == NULL)
     gtk_widget_destroy (GTK_WIDGET (window));
@@ -1921,7 +1838,7 @@
 }
 
 void
-terminal_window_update_geometry (TerminalWindow *window)
+update_geometry (TerminalWindow *window)
 {
   GdkGeometry hints;
   GtkWidget *widget;  
@@ -2264,6 +2181,26 @@
                              NULL, name, -1);
 
   g_free (geometry);
+}
+
+static void
+size_request_callback (GtkWidget *widget,
+               GtkRequisition *requisition,
+               TerminalWindow *window)
+{
+  if (!window->priv->active_term)
+    return;
+
+#ifdef DEBUG_GEOMETRY
+  g_fprintf (stderr, "vbox size-request callback with size %dx%d\n",
+             requisition->width, requisition->height);
+#endif
+
+  if (GTK_WIDGET_MAPPED (window)) {
+    gtk_window_resize (GTK_WINDOW (window), requisition->width,
+                       requisition->height);
+  }
+  update_geometry (window);
 }
 
 static void
