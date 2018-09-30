$OpenBSD: patch-daemon_gdm-session_c,v 1.12 2017/05/10 10:18:15 ajacoutot Exp $

REVERT - OpenBSD does not have a systemd implementation (we need ConsoleKit)
From 9be58c9ec9a3a411492a5182ac4b0d51fdc3a323 Mon Sep 17 00:00:00 2001
From: Ray Strode <rstrode@redhat.com>
Date: Fri, 12 Jun 2015 13:48:52 -0400
Subject: require logind support

REVERT - OpenBSD does not have a systemd implementation (we need ConsoleKit)
From a9cacb929470eb82582396984c61d5b611bfeb1a Mon Sep 17 00:00:00 2001
From: Ray Strode <rstrode@redhat.com>
Date: Fri, 12 Jun 2015 14:33:40 -0400
Subject: session: drop session-type property

Index: daemon/gdm-session.c
--- daemon/gdm-session.c.orig
+++ daemon/gdm-session.c
@@ -3076,6 +3076,10 @@ gdm_session_bypasses_xsession (GdmSession *self)
         g_return_val_if_fail (self != NULL, FALSE);
         g_return_val_if_fail (GDM_IS_SESSION (self), FALSE);
 
+        if (!LOGIND_RUNNING()) {
+                return GDM_SESSION_DISPLAY_MODE_REUSE_VT;
+        }
+
 #ifdef ENABLE_WAYLAND_SUPPORT
         if (gdm_session_is_wayland_session (self)) {
                 bypasses_xsession = TRUE;
@@ -3168,6 +3172,27 @@ gdm_session_select_program (GdmSession *self,
         g_free (self->priv->selected_program);
 
         self->priv->selected_program = g_strdup (text);
+}
+
+void
+gdm_session_select_session_type (GdmSession *self,
+                                 const char *text)
+{
+        GHashTableIter iter;
+        gpointer key, value;
+
+        g_debug ("GdmSession: selecting session type '%s'", text);
+
+        g_hash_table_iter_init (&iter, self->priv->conversations);
+        while (g_hash_table_iter_next (&iter, &key, &value)) {
+                GdmSessionConversation *conversation;
+
+                conversation = (GdmSessionConversation *) value;
+
+                gdm_dbus_worker_call_set_session_type (conversation->worker_proxy,
+                                                       text,
+                                                       NULL, NULL, NULL);
+        }
 }
 
 void
