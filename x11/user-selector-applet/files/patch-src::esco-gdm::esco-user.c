--- src/esco-gdm/esco-user.c.orig	Mon Jun 21 00:47:26 2004
+++ src/esco-gdm/esco-user.c	Mon Jun 21 00:40:35 2004
@@ -611,6 +611,8 @@
 
   mgr = esco_screen_manager_get_default ();
 
+  user->screen_changed_id = g_signal_connect (mgr, "new-screen",
+					      G_CALLBACK (screen_changed_cb), user);
   user->screen_changed_id = g_signal_connect (mgr, "screen-changed",
 					      G_CALLBACK (screen_changed_cb), user);
   user->screen_closed_id = g_signal_connect (mgr, "screen-closed", G_CALLBACK (screen_closed_cb),
