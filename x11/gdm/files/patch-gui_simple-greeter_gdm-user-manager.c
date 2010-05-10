--- gui/simple-greeter/gdm-user-manager.c.orig	2009-12-21 17:36:30.000000000 +0100
+++ gui/simple-greeter/gdm-user-manager.c	2009-12-27 22:34:26.000000000 +0100
@@ -66,6 +66,8 @@
 
 #ifdef __sun
 #define DEFAULT_MINIMAL_UID     100
+#elif defined(__FreeBSD__)
+#define DEFAULT_MINIMAL_UID     1000
 #else
 #define DEFAULT_MINIMAL_UID     500
 #endif
@@ -1414,17 +1416,24 @@ reload_passwd (GdmUserManager *manager)
         GSList        *new_users;
         GSList        *list;
         GSList        *dup;
+#ifndef __FreeBSD__
         FILE          *fp;
+#endif
 
         old_users = NULL;
         new_users = NULL;
 
+#ifdef __FreeBSD__
+        setpwent ();
+#else
+
         errno = 0;
         fp = fopen (PATH_PASSWD, "r");
         if (fp == NULL) {
                 g_warning ("Unable to open %s: %s", PATH_PASSWD, g_strerror (errno));
                 goto out;
         }
+#endif
 
         g_hash_table_foreach (manager->priv->users, listify_hash_values_hfunc, &old_users);
         g_slist_foreach (old_users, (GFunc) g_object_ref, NULL);
@@ -1443,9 +1452,15 @@ reload_passwd (GdmUserManager *manager)
         } else {
                 g_debug ("GdmUserManager: include_all is TRUE");
 
+#ifdef __FreeBSD__
+		for (pwent = getpwent ();
+		     pwent != NULL;
+		     pwent = getpwent()) {
+#else
                 for (pwent = fgetpwent (fp);
                      pwent != NULL;
                      pwent = fgetpwent (fp)) {
+#endif
                         GdmUser *user;
 
                         user = NULL;
@@ -1521,7 +1536,11 @@ reload_passwd (GdmUserManager *manager)
  out:
         /* Cleanup */
 
+#ifdef __FreeBSD__
+	endpwent ();
+#else
         fclose (fp);
+#endif
 
         g_slist_foreach (new_users, (GFunc) g_object_thaw_notify, NULL);
         g_slist_foreach (new_users, (GFunc) g_object_unref, NULL);
