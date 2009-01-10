--- gui/simple-greeter/gdm-user-manager.c.orig	2008-04-29 13:38:43.000000000 -0400
+++ gui/simple-greeter/gdm-user-manager.c	2008-05-03 13:27:52.000000000 -0400
@@ -1269,17 +1269,23 @@ reload_passwd (GdmUserManager *manager)
         GSList        *old_users;
         GSList        *new_users;
         GSList        *list;
-        FILE          *fp;
+#ifndef __FreeBSD__
+       FILE          *fp;
+#endif
 
         old_users = NULL;
         new_users = NULL;
 
+#ifdef __FreeBSD__
+        setpwent ();
+#else
         errno = 0;
         fp = fopen (PATH_PASSWD, "r");
         if (fp == NULL) {
                 g_warning ("Unable to open %s: %s", PATH_PASSWD, g_strerror (errno));
                 goto out;
         }
+#endif
 
         g_hash_table_foreach (manager->priv->users, listify_hash_values_hfunc, &old_users);
         g_slist_foreach (old_users, (GFunc) g_object_ref, NULL);
@@ -1292,7 +1298,11 @@ reload_passwd (GdmUserManager *manager)
                 }
         }
 
+#ifdef __FreeBSD__
+        for (pwent = getpwent (); pwent != NULL; pwent = getpwent ()) {
+#else
         for (pwent = fgetpwent (fp); pwent != NULL; pwent = fgetpwent (fp)) {
+#endif
                 GdmUser *user;
 
                 user = NULL;
@@ -1355,7 +1365,11 @@ reload_passwd (GdmUserManager *manager)
  out:
         /* Cleanup */
 
+#ifdef __FreeBSD__
+	endpwent ();
+#else
         fclose (fp);
+#endif
 
         g_slist_foreach (new_users, (GFunc) g_object_thaw_notify, NULL);
         g_slist_foreach (new_users, (GFunc) g_object_unref, NULL);
