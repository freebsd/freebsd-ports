--- plugins/deskno.c~	Sat Dec 18 17:37:12 2004
+++ plugins/deskno.c	Sat Dec 18 17:37:30 2004
@@ -25,10 +25,10 @@
 static  void
 clicked( GtkWidget *widget, gpointer data)
 {
-    ENTER;
     int desknum = get_net_current_desktop();
     int desks = get_net_number_of_desktops();
     int newdesk;
+    ENTER;
     if(desknum == (desks - 1))
 	newdesk = 0;
     else
