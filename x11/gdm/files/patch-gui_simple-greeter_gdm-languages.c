--- gui/simple-greeter/gdm-languages.c.orig	2009-07-20 03:09:09.000000000 +0200
+++ gui/simple-greeter/gdm-languages.c	2009-07-20 10:02:41.000000000 +0200
@@ -168,13 +168,13 @@ gdm_parse_language_name (const char *nam
                         *codesetp = NULL;
                 }
 
-                if (*codesetp != NULL) {
+/*                if (*codesetp != NULL) {
                         char *codeset;
 
                         codeset = normalize_codeset (*codesetp);
                         g_free (*codesetp);
                         *codesetp = codeset;
-                }
+                }*/
         }
 
         if (modifierp != NULL) {
@@ -314,7 +314,7 @@ language_name_has_translations (const ch
         const char  *name;
         gboolean     has_translations;
 
-        path = g_build_filename (GNOMELOCALEDIR, language_name, "LC_MESSAGES", NULL);
+        path = g_build_filename ("/usr/share/locale", language_name, "LC_MESSAGES", NULL);
 
         has_translations = FALSE;
         dir = g_dir_open (path, 0, NULL);
@@ -352,7 +352,7 @@ add_locale (const char *language_name)
         if (language_name_is_utf8 (language_name)) {
                 name = g_strdup (language_name);
         } else {
-                name = g_strdup_printf ("%s.utf8", language_name);
+                name = g_strdup_printf ("%s.UTF-8", language_name);
 
                 if (!language_name_is_utf8 (name)) {
                         g_free (name);
@@ -501,7 +501,7 @@ collect_locales_from_directory (void)
         int             ndirents;
         int             cnt;
 
-        ndirents = scandir (LIBLOCALEDIR, &dirents, select_dirs, alphasort);
+        ndirents = scandir ("/usr/share/locale", &dirents, select_dirs, alphasort);
 
         for (cnt = 0; cnt < ndirents; ++cnt) {
                 add_locale (dirents[cnt]->d_name);
