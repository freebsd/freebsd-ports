--- src/interface.c.orig	Sat Oct 12 14:53:45 2002
+++ src/interface.c	Sat Oct 12 15:04:53 2002
@@ -111,8 +111,8 @@
   gtk_widget_show (vbox3);
   gtk_box_pack_start (GTK_BOX (dialog_vbox1), vbox3, TRUE, TRUE, 0);
 
-	version_button1 = gtk_radio_button_new_with_label(NULL, "I am using metacity 2.3.x");
-	version_button2 = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON (version_button1), "I am using metacity 2.4.x");
+	version_button2 = gtk_radio_button_new_with_label(NULL, "I am using metacity 2.4.x");
+	version_button1 = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON (version_button2), "I am using metacity 2.3.x");
 	gtk_box_pack_start (GTK_BOX (vbox3), version_button1, TRUE, TRUE, 0);
 	gtk_box_pack_start (GTK_BOX (vbox3), version_button2, TRUE, TRUE, 0);
 	gtk_widget_show (version_button1);
