--- daemon/gdm-display.c.orig	2022-01-12 14:15:56 UTC
+++ daemon/gdm-display.c
@@ -245,8 +245,13 @@ setup_xhost_auth (XHostAddress              *host_entr
         host_entries[1].address   = "localuser\0" GDM_USERNAME;
         host_entries[1].length    = sizeof ("localuser\0" GDM_USERNAME);
         host_entries[2].family    = FamilyServerInterpreted;
+#if defined(__OpenBSD__)
+        host_entries[2].address   = "localuser\0_gnome-initial-setup";
+        host_entries[2].length    = sizeof ("localuser\0_gnome-initial-setup");
+#else
         host_entries[2].address   = "localuser\0gnome-initial-setup";
         host_entries[2].length    = sizeof ("localuser\0gnome-initial-setup");
+#endif
 }
 
 gboolean
