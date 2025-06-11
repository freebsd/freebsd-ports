--- daemon/gdm-session.c.orig	2024-09-16 13:28:26 UTC
+++ daemon/gdm-session.c
@@ -45,7 +45,9 @@
 
 #include <json-glib/json-glib.h>
 
+#ifdef WITH_SYSTEMD
 #include <systemd/sd-login.h>
+#endif
 
 #include "gdm-session.h"
 #include "gdm-session-glue.h"
@@ -120,6 +122,9 @@ struct _GdmSession
 
         /* object lifetime scope */
         char                *session_type;
+#ifdef WITH_CONSOLE_KIT
+        char                *session_class;
+#endif
         char                *display_name;
         char                *display_hostname;
         char                *display_device;
@@ -387,7 +392,9 @@ get_system_session_dirs (GdmSession *self,
                 DATADIR "/xsessions/",
         };
 
+#ifdef ENABLE_WAYLAND_SUPPORT
         static const char *wayland_search_dir = DATADIR "/wayland-sessions/";
+#endif
 
         search_array = g_array_new (TRUE, TRUE, sizeof (char *));
 
@@ -3386,6 +3393,7 @@ gdm_session_is_frozen (GdmSession *self)
 gboolean
 gdm_session_is_frozen (GdmSession *self)
 {
+#ifdef WITH_SYSTEMD
         g_autofree char *cgroup = NULL, *path = NULL, *data = NULL;
         g_auto (GStrv) arr = NULL;
 
@@ -3408,6 +3416,7 @@ gdm_session_is_frozen (GdmSession *self)
                 if (g_str_equal (arr[i], "frozen"))
                         return g_str_equal (arr[i + 1], "1");
         }
+#endif
         return FALSE;
 }
 
