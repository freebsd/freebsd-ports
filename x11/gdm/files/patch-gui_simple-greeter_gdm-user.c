--- gui/simple-greeter/gdm-user.c.orig	2009-12-16 17:52:36.000000000 -0500
+++ gui/simple-greeter/gdm-user.c	2009-12-18 21:43:38.000000000 -0500
@@ -425,6 +425,7 @@ _gdm_user_update (GdmUser             *u
         /* Display Name */
         if (pwent->pw_gecos && pwent->pw_gecos[0] != '\0') {
                 gchar *first_comma = NULL;
+                gchar *ampersand;
                 gchar *valid_utf8_name = NULL;
 
                 if (g_utf8_validate (pwent->pw_gecos, -1, NULL)) {
@@ -449,6 +450,23 @@ _gdm_user_update (GdmUser             *u
                         g_free (real_name);
                         real_name = NULL;
                 }
+
+                while (real_name != NULL && (ampersand = strchr (real_name, '&')) != NULL) {
+                        gchar *temp_real_name1;
+                        gchar *temp_real_name2;
+                        gchar *temp_name;
+
+                        temp_real_name1 = g_strndup (real_name,
+                                        (ampersand - real_name));
+                        temp_real_name2 = g_strdup (ampersand + 1);
+                        temp_name = g_strdup (pwent->pw_name);
+                        temp_name[0] = toupper (temp_name[0]);
+                        g_free (real_name);
+                        real_name = g_strdup_printf ("%s%s%s", temp_real_name1, temp_name, temp_real_name2);
+                        g_free (temp_real_name1);
+                        g_free (temp_real_name2);
+                        g_free (temp_name);
+                }
         } else {
                 real_name = NULL;
         }
