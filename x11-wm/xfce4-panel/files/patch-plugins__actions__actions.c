--- ./plugins/actions/actions.c.orig	2012-04-28 20:31:35.000000000 +0000
+++ ./plugins/actions/actions.c	2013-02-18 19:39:14.000000000 +0000
@@ -705,7 +705,7 @@
 
   if (timeout->time_left == 0)
     {
-      /* unattended shutdown, so don't allow apps to cancel shutdown */
+      /* unattended shutdown, don't save the session to avoid blocking the logout */
       timeout->unattended = TRUE;
 
       gtk_dialog_response (GTK_DIALOG (timeout->dialog),
@@ -928,22 +928,22 @@
     {
     case ACTION_TYPE_LOGOUT:
       succeed = actions_plugin_action_dbus_xfsm ("Logout", FALSE,
-                                                 unattended, &error);
+                                                 !unattended, &error);
       break;
 
     case ACTION_TYPE_LOGOUT_DIALOG:
       succeed = actions_plugin_action_dbus_xfsm ("Logout", TRUE,
-                                                 unattended, &error);
+                                                 !unattended, &error);
       break;
 
     case ACTION_TYPE_RESTART:
       succeed = actions_plugin_action_dbus_xfsm ("Restart", FALSE,
-                                                 unattended, &error);
+                                                 !unattended, &error);
       break;
 
     case ACTION_TYPE_SHUTDOWN:
       succeed = actions_plugin_action_dbus_xfsm ("Shutdown", FALSE,
-                                                 unattended, &error);
+                                                 !unattended, &error);
       break;
 
     case ACTION_TYPE_HIBERNATE:
