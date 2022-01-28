--- daemon/gdm-session.c.orig	2022-01-12 14:15:56 UTC
+++ daemon/gdm-session.c
@@ -116,6 +116,9 @@ struct _GdmSession
 
         /* object lifetime scope */
         char                *session_type;
+#ifdef WITH_CONSOLE_KIT
+        char                *session_class;
+#endif
         char                *display_name;
         char                *display_hostname;
         char                *display_device;
@@ -371,7 +374,9 @@ get_system_session_dirs (GdmSession *self,
                 DATADIR "/xsessions/",
         };
 
+#ifdef ENABLE_WAYLAND_SUPPORT
         static const char *wayland_search_dir = DATADIR "/wayland-sessions/";
+#endif
 
         search_array = g_array_new (TRUE, TRUE, sizeof (char *));
 
