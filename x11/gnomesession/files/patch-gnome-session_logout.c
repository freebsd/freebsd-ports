--- gnome-session/logout.c.orig	Sun May  9 15:45:34 2004
+++ gnome-session/logout.c	Sun May  9 15:48:29 2004
@@ -37,12 +37,20 @@
 
 static gchar *halt_command[] =
 {
+#ifdef __FreeBSD__
+  HALT_COMMAND, "-p", "now", NULL
+#else
   HALT_COMMAND, NULL
+#endif
 };
 
 static gchar *reboot_command[] =
 {
+#ifdef __FreeBSD__
+  REBOOT_COMMAND, "-r", "now", NULL
+#else
   REBOOT_COMMAND, NULL
+#endif
 };
 
 /* What action to take upon shutdown */
@@ -401,8 +409,12 @@
    */
   s = g_strconcat ("/var/lock/console/", g_get_user_name (), NULL);
   t = g_strconcat ("/var/run/console/", g_get_user_name (), NULL);
+#ifndef __FreeBSD__
   if (((geteuid () == 0) || g_file_exists (t) || g_file_exists(s)) &&
       access (halt_command[0], X_OK) == 0)
+#else
+  if (access (halt_command[0], X_OK) == 0)
+#endif
     {
       GtkWidget *title, *spacer;
       GtkWidget *action_vbox, *hbox;
