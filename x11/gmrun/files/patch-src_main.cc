--- src/main.cc.orig	2003-11-16 10:55:07 UTC
+++ src/main.cc
@@ -541,7 +541,6 @@ int main(int argc, char **argv)
   gtk_widget_set_name(win, "Msh_Run_Window");
   gtk_window_set_title(GTK_WINDOW(win), "Execute program feat. completion");
   gtk_window_set_policy(GTK_WINDOW(win), FALSE, FALSE, TRUE);
-  // gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);
   gtk_container_set_border_width(GTK_CONTAINER(win), 4);
   gtk_signal_connect(GTK_OBJECT(win), "destroy",
                      GTK_SIGNAL_FUNC(gtk_main_quit), NULL);
@@ -653,7 +652,10 @@ int main(int argc, char **argv)
   }
   else
   {
-    gtk_widget_set_uposition(win, prefs_left, prefs_top);
+  	if ((prefs_top == -1) && (prefs_left == -1))
+		gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);
+	else
+		gtk_widget_set_uposition(win, prefs_left, prefs_top);
   }
 
   gtk_widget_show(win);
