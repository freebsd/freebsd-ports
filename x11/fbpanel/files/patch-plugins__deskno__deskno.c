--- ./plugins/deskno/deskno.c.orig	2010-03-02 05:26:40.000000000 -0800
+++ ./plugins/deskno/deskno.c	2010-11-17 11:06:07.000000000 -0800
@@ -57,7 +57,7 @@
 
     ENTER;
     dc->deskno = get_net_current_desktop();
-    sprintf(buffer, "<b>%d</b>", dc->deskno + 1);
+    snprintf(buffer, sizeof(buffer), "<b>%d</b>", dc->deskno + 1);
     gtk_label_set_markup(GTK_LABEL(dc->namew), buffer);
     RET(TRUE);
 }
