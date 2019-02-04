https://bugs.launchpad.net/lightdm/+bug/790186

--- liblightdm-gobject/language.c.orig	2018-08-29 22:30:07 UTC
+++ liblightdm-gobject/language.c
@@ -57,6 +57,12 @@ G_DEFINE_TYPE_WITH_PRIVATE (LightDMLanguage, lightdm_l
 static gboolean have_languages = FALSE;
 static GList *languages = NULL;
 
+static gboolean
+is_utf8 (const gchar *code)
+{
+    return g_strrstr (code, ".utf8") || g_strrstr (code, ".UTF-8");
+}
+
 static void
 update_languages (void)
 {
@@ -83,7 +89,7 @@ update_languages (void)
                 continue;
 
             /* Ignore the non-interesting languages */
-            if (strcmp (command, "locale -a") == 0 && !g_strrstr (code, ".utf8"))
+            if (strcmp (command, "locale -a") == 0 && !is_utf8 (code))
                 continue;
 
             LightDMLanguage *language = g_object_new (LIGHTDM_TYPE_LANGUAGE, "code", code, NULL);
@@ -94,12 +100,6 @@ update_languages (void)
     have_languages = TRUE;
 }
 
-static gboolean
-is_utf8 (const gchar *code)
-{
-    return g_strrstr (code, ".utf8") || g_strrstr (code, ".UTF-8");
-}
-
 /* Get a valid locale name that can be passed to setlocale(), so we always can use nl_langinfo() to get language and country names. */
 static gchar *
 get_locale_name (const gchar *code)
@@ -131,7 +131,7 @@ get_locale_name (const gchar *code)
     for (gint i = 0; avail_locales[i]; i++)
     {
         const gchar *loc = avail_locales[i];
-        if (!g_strrstr (loc, ".utf8"))
+        if (!is_utf8 (loc))
             continue;
         if (g_str_has_prefix (loc, language))
             return g_strdup (loc);
@@ -214,10 +214,16 @@ lightdm_language_get_name (LightDMLanguage *language)
         if (locale)
         {
             const gchar *current = setlocale (LC_ALL, NULL);
+#ifdef LC_IDENTIFICATION
             setlocale (LC_IDENTIFICATION, locale);
+#endif
             setlocale (LC_MESSAGES, "");
 
+#ifdef _NL_IDENTIFICATION_LANGUAGE
             const gchar *language_en = nl_langinfo (_NL_IDENTIFICATION_LANGUAGE);
+#else
+            const gchar *language_en = "Unknown";
+#endif
             if (language_en && strlen (language_en) > 0)
                 priv->name = g_strdup (dgettext ("iso_639_3", language_en));
 
@@ -254,10 +260,16 @@ lightdm_language_get_territory (LightDMLanguage *langu
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
 
