--- gtkcolorsel.c.orig	Tue Oct 21 22:18:28 2003
+++ gtkcolorsel.c	Tue Oct 21 22:18:28 2003
@@ -320,9 +320,9 @@
 	gtk_container_add (GTK_CONTAINER (about_window), vbox);
 	gtk_widget_show (vbox);
 
-	label = gtk_label_new ("\nGyrosCoPe HTML colour picker\nVersion 1.0\n30th January, 1999
-	\n    http://www.millar.u-net.com/gyroscope.html    \n
-	neil@millar.u-net.com\n");
+	label = gtk_label_new ("\nGyrosCoPe HTML colour picker\nVersion 1.0\n30th January, 1999\n"\
+"	\n    http://www.millar.u-net.com/gyroscope.html    \n"\
+"	neil@millar.u-net.com\n");
 	gtk_box_pack_start (GTK_BOX (vbox), label, TRUE, TRUE, 0);
 	gtk_widget_show (label);
 
