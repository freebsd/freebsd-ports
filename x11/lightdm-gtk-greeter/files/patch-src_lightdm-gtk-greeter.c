--- src/lightdm-gtk-greeter.c.orig	2017-06-08 17:51:50 UTC
+++ src/lightdm-gtk-greeter.c
@@ -2930,11 +2930,7 @@ main (int argc, char **argv)
             gchar *label;
             GtkWidget *radiomenuitem;
 
-            country = lightdm_language_get_territory (language);
-            if (country)
-                label = g_strdup_printf ("%s - %s", lightdm_language_get_name (language), country);
-            else
-                label = g_strdup (lightdm_language_get_name (language));
+	    label = g_strdup (lightdm_language_get_code (language));
 
             code = lightdm_language_get_code (language);
             gchar *modifier = strchr (code, '@');
