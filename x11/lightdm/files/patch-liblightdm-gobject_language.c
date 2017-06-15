https://bugs.launchpad.net/lightdm/+bug/790186

--- liblightdm-gobject/language.c.orig	2016-12-09 01:04:48 UTC
+++ liblightdm-gobject/language.c
@@ -248,10 +248,16 @@ lightdm_language_get_name (LightDMLangua
         if (locale)
         {
             gchar *current = setlocale (LC_ALL, NULL);
+#ifdef LC_IDENTIFICATION
             setlocale (LC_IDENTIFICATION, locale);
+#endif
             setlocale (LC_MESSAGES, "");
 
+#ifdef _NL_IDENTIFICATION_LANGUAGE
             gchar *language_en = nl_langinfo (_NL_IDENTIFICATION_LANGUAGE);
+#else
+            gchar *language_en = "Unknown";
+#endif
             if (language_en && strlen (language_en) > 0)
                 priv->name = g_strdup (dgettext ("iso_639_3", language_en));
 
@@ -291,10 +297,16 @@ lightdm_language_get_territory (LightDML
         if (locale)
         {
             gchar *current = setlocale (LC_ALL, NULL);
+#ifdef LC_IDENTIFICATION
             setlocale (LC_IDENTIFICATION, locale);
+#endif
             setlocale (LC_MESSAGES, "");
 
+#ifdef _NL_IDENTIFICATION_TERRITORY
             gchar *country_en = nl_langinfo (_NL_IDENTIFICATION_TERRITORY);
+#else
+            gchar *country_en = "Unknown";
+#endif
             if (country_en && strlen (country_en) > 0 && g_strcmp0 (country_en, "ISO") != 0)
                 priv->territory = g_strdup (dgettext ("iso_3166", country_en));
 
