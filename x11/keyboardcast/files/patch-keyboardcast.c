--- keyboardcast.orig	2013-12-20 10:06:27.000000000 +0200
+++ keyboardcast.c	2013-12-20 10:07:10.000000000 +0200
@@ -242,7 +242,7 @@
                                                "text", 2, NULL );
 
   glade_xml_signal_connect( xml, "key_event", G_CALLBACK( key_event ) );
-  glade_xml_signal_connect( xml, "gtk_exit", G_CALLBACK( gtk_exit ) );
+  glade_xml_signal_connect( xml, "gtk_main_quit", G_CALLBACK( gtk_main_quit ) );
   glade_xml_signal_connect_data( xml, "expanded",
                                  G_CALLBACK( expanded ), window );
   glade_xml_signal_connect_data( xml, "button_clicked",
