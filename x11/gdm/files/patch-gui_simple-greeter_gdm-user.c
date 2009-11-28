--- gui/simple-greeter/gdm-user.c.orig	2009-07-20 03:09:09.000000000 +0200
+++ gui/simple-greeter/gdm-user.c	2009-07-20 10:09:41.000000000 +0200
@@ -427,6 +427,7 @@ _gdm_user_update (GdmUser             *u
         /* Display Name */
         if (pwent->pw_gecos && pwent->pw_gecos[0] != '\0') {
                 gchar *first_comma;
+		gchar *ampersand;
                 gchar *real_name_utf8;
 
                 real_name_utf8 = g_locale_to_utf8 (pwent->pw_gecos, -1, NULL, NULL, NULL);
@@ -443,6 +444,23 @@ _gdm_user_update (GdmUser             *u
                         g_free (real_name);
                         real_name = NULL;
                 }
+
+		while (real_name != NULL && (ampersand = strchr (real_name, '&')) != NULL) {
+			gchar *temp_real_name1;
+			gchar *temp_real_name2;
+			gchar *temp_name;
+
+			temp_real_name1 = g_strndup (real_name,
+					(ampersand - real_name));
+			temp_real_name2 = g_strdup (ampersand + 1);
+			temp_name = g_strdup (pwent->pw_name);
+			temp_name[0] = toupper (temp_name[0]);
+			g_free (real_name);
+			real_name = g_strdup_printf ("%s%s%s", temp_real_name1, temp_name, temp_real_name2);
+			g_free (temp_real_name1);
+			g_free (temp_real_name2);
+			g_free (temp_name);
+		}
         } else {
                 real_name = NULL;
         }
