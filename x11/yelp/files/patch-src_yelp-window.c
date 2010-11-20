--- src/yelp-window.c.orig	2010-10-16 23:06:05.000000000 +0400
+++ src/yelp-window.c	2010-10-17 03:58:57.000000000 +0400
@@ -1555,28 +1555,26 @@
 
     gtk_label_set_mnemonic_widget (GTK_LABEL (label), priv->find_entry);
 
-    box = gtk_hbox_new (FALSE, 0);
     arrow = gtk_arrow_new (GTK_ARROW_LEFT, GTK_SHADOW_NONE);
     label = gtk_label_new_with_mnemonic (_("Find _Previous"));
-    gtk_box_pack_start (GTK_BOX (box), arrow, FALSE, FALSE, 0);
-    gtk_box_pack_start (GTK_BOX (box), label, TRUE, TRUE, 0);
-    priv->find_prev = gtk_tool_button_new (box, NULL);
+    priv->find_prev = gtk_tool_button_new (arrow, NULL);
+    gtk_tool_button_set_label_widget (GTK_TOOL_BUTTON (priv->find_prev), label);
     g_signal_connect (priv->find_prev,
                       "clicked",
                       G_CALLBACK (window_find_clicked_cb),
                       window);
+    gtk_tool_item_set_is_important (priv->find_prev, TRUE);
     gtk_toolbar_insert (GTK_TOOLBAR (find_bar), priv->find_prev, -1);
 
-    box = gtk_hbox_new (FALSE, 0);
     arrow = gtk_arrow_new (GTK_ARROW_RIGHT, GTK_SHADOW_NONE);
     label = gtk_label_new_with_mnemonic (_("Find _Next"));
-    gtk_box_pack_start (GTK_BOX (box), arrow, FALSE, FALSE, 0);
-    gtk_box_pack_start (GTK_BOX (box), label, TRUE, TRUE, 0);
-    priv->find_next = gtk_tool_button_new (box, NULL);
+    priv->find_next = gtk_tool_button_new (arrow, NULL);
+    gtk_tool_button_set_label_widget (GTK_TOOL_BUTTON (priv->find_next), label);
     g_signal_connect (priv->find_next,
 		      "clicked",
 		      G_CALLBACK (window_find_clicked_cb),
 		      window);
+    gtk_tool_item_set_is_important (priv->find_next, TRUE);
     gtk_toolbar_insert (GTK_TOOLBAR (find_bar), priv->find_next, -1);
 
     priv->find_sep = gtk_separator_tool_item_new ();
