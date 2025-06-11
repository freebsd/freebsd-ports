--- libgdm/gdm-sessions.c.orig	2024-05-29 15:50:27 UTC
+++ libgdm/gdm-sessions.c
@@ -35,7 +35,9 @@
 #include <glib/gi18n.h>
 #include <glib/gstdio.h>
 
+#ifdef WITH_SYSTEMD
 #include <systemd/sd-login.h>
+#endif
 
 #include "gdm-sessions.h"
 
@@ -60,6 +62,7 @@ gdm_session_file_free (GdmSessionFile *session)
   g_free (session);
 }
 
+#ifdef WITH_SYSTEMD
 static char *
 get_systemd_session (void)
 {
@@ -104,6 +107,7 @@ get_systemd_seat (void)
 
         return g_steal_pointer (&seat);
 }
+#endif
 
 /* adapted from gnome-menus desktop-entries.c */
 static gboolean
@@ -138,7 +142,9 @@ key_file_is_relevant (GKeyFile     *key_file)
                 g_error_free (error);
         }
 
+#ifdef WITH_SYSTEMD
         seat = get_systemd_seat ();
+#endif
 
         only_headless_allowed = seat == NULL;
 
