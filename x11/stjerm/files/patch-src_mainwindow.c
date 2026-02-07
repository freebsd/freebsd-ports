--- src/mainwindow.c~	2011-07-19 16:52:33.000000000 -0500
+++ src/mainwindow.c	2011-10-12 17:26:33.324269165 -0500
@@ -322,7 +322,7 @@ void mainwindow_create_tab(void)
     }
 
     char buffer [100];
-    sprintf(buffer, "%s %d", conf_get_term_name(), activetab + 1);
+    sprintf(buffer, "%s %d", conf_get_term_name(), tabcount);
     GtkLabel* tmp_label = GTK_LABEL(gtk_label_new(buffer));
 
     if(conf_get_opacity() < 100)
