--- unix/apc_misc.c.orig	2015-11-04 21:39:04 UTC
+++ unix/apc_misc.c
@@ -1239,12 +1239,14 @@ apc_beep_tone( int freq, int duration)
    return true;
 }
 
+#ifdef WITH_GTK2
 #include <gtk/gtk.h>
 
 static void _gtk_callback( GtkWidget *widget, gpointer   data )
 {
     g_print ("Hello again - %s was pressed\n", (char *) data);
 }
+#endif
 
 char *
 apc_system_action( const char *s)
