--- ./xfce4-session/xfsm-manager.c.orig	2012-04-28 20:43:27.000000000 +0000
+++ ./xfce4-session/xfsm-manager.c	2013-02-18 19:14:56.000000000 +0000
@@ -98,6 +98,7 @@
 
   XfsmShutdownType  shutdown_type;
   XfsmShutdown     *shutdown_helper;
+  gboolean          save_session;
 
   gboolean         session_chooser;
   gchar           *session_name;
@@ -230,6 +231,7 @@
   manager->failsafe_mode = TRUE;
   manager->shutdown_type = XFSM_SHUTDOWN_LOGOUT;
   manager->shutdown_helper = xfsm_shutdown_get ();
+  manager->save_session = TRUE;
 
   manager->pending_properties = g_queue_new ();
   manager->starting_properties = g_queue_new ();
@@ -989,7 +991,9 @@
           XfsmClient *cl = lp->data;
           if (xfsm_client_get_state (cl) == XFSM_CLIENT_INTERACTING)
             {
-              xfsm_client_set_state (cl, XFSM_CLIENT_WAITFORINTERACT);
+              /* a client is already interacting, so new client has to wait */
+              xfsm_client_set_state (client, XFSM_CLIENT_WAITFORINTERACT);
+              xfsm_manager_cancel_client_save_timeout(manager, client);
               return;
             }
         }
@@ -1138,44 +1142,47 @@
         }
     }
 
-  if (!shutdown || shutdown_save)
+  /* don't save the session if shutting down without save */
+  manager->save_session = !shutdown || shutdown_save;
+
+  if (save_type == SmSaveBoth && !manager->save_session)
     {
-      xfsm_manager_set_state (manager,
-                              shutdown
-                              ? XFSM_MANAGER_SHUTDOWN
-                              : XFSM_MANAGER_CHECKPOINT);
+      /* saving the session, so clients should
+       * (prompt to) save the user data only */
+      save_type = SmSaveGlobal;
+    }
 
-      /* handle legacy applications first! */
-      xfsm_legacy_perform_session_save ();
+  xfsm_manager_set_state (manager,
+                          shutdown
+                          ? XFSM_MANAGER_SHUTDOWN
+                          : XFSM_MANAGER_CHECKPOINT);
 
-      for (lp = g_queue_peek_nth_link (manager->running_clients, 0);
-           lp;
-           lp = lp->next)
-        {
-          XfsmClient *client = lp->data;
-          XfsmProperties *properties = xfsm_client_get_properties (client);
-          const gchar *program;
+  /* handle legacy applications first! */
+  if (manager->save_session)
+      xfsm_legacy_perform_session_save ();
 
-          /* xterm's session management is broken, so we won't
-           * send a SAVE YOURSELF to xterms */
-          program = xfsm_properties_get_string (properties, SmProgram);
-          if (program != NULL && strcasecmp (program, "xterm") == 0)
-            continue;
+  for (lp = g_queue_peek_nth_link (manager->running_clients, 0);
+       lp;
+       lp = lp->next)
+    {
+      XfsmClient *client = lp->data;
+      XfsmProperties *properties = xfsm_client_get_properties (client);
+      const gchar *program;
 
-          if (xfsm_client_get_state (client) != XFSM_CLIENT_SAVINGLOCAL)
-            {
-              SmsSaveYourself (xfsm_client_get_sms_connection (client), save_type, shutdown,
-                               interact_style, fast);
-            }
+      /* xterm's session management is broken, so we won't
+       * send a SAVE YOURSELF to xterms */
+      program = xfsm_properties_get_string (properties, SmProgram);
+      if (program != NULL && strcasecmp (program, "xterm") == 0)
+        continue;
 
-          xfsm_client_set_state (client, XFSM_CLIENT_SAVING);
-          xfsm_manager_start_client_save_timeout (manager, client);
+      if (xfsm_client_get_state (client) != XFSM_CLIENT_SAVINGLOCAL)
+        {
+          SmsSaveYourself (xfsm_client_get_sms_connection (client), save_type, shutdown,
+                           interact_style, fast);
         }
-    }
-  else
-    {
-      /* shutdown session without saving */
-      xfsm_manager_perform_shutdown (manager);
+
+      xfsm_client_set_state (client, XFSM_CLIENT_SAVING);
+      xfsm_manager_start_client_save_timeout (manager, client);
     }
 }
 
@@ -1249,7 +1256,12 @@
                                  XfsmClient  *client,
                                  gboolean     success)
 {
-  if (xfsm_client_get_state (client) != XFSM_CLIENT_SAVING && xfsm_client_get_state (client) != XFSM_CLIENT_SAVINGLOCAL)
+  /* In xfsm_manager_interact_done we send SmsShutdownCancelled to clients in
+     XFSM_CLIENT_WAITFORINTERACT state. They respond with SmcSaveYourselfDone
+     (xsmp_shutdown_cancelled in libxfce4ui library) so we allow it here. */
+  if (xfsm_client_get_state (client) != XFSM_CLIENT_SAVING &&
+      xfsm_client_get_state (client) != XFSM_CLIENT_SAVINGLOCAL &&
+      xfsm_client_get_state (client) != XFSM_CLIENT_WAITFORINTERACT)
     {
       xfsm_verbose ("Client Id = %s send SAVE YOURSELF DONE, while not being "
                     "in save mode. Prepare to be nuked!\n",
@@ -1521,7 +1533,8 @@
   xfsm_verbose ("Manager finished SAVE YOURSELF, session data will be stored now.\n\n");
 
   /* all clients done, store session data */
-  xfsm_manager_store_session (manager);
+  if (manager->save_session)
+    xfsm_manager_store_session (manager);
 
   if (manager->state == XFSM_MANAGER_CHECKPOINT)
     {
