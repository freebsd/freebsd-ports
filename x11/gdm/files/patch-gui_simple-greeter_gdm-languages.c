--- gui/simple-greeter/gdm-languages.c.orig	2008-11-22 17:16:42.000000000 -0500
+++ gui/simple-greeter/gdm-languages.c	2008-11-22 17:29:05.000000000 -0500
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
@@ -353,7 +353,7 @@ add_locale (const char *language_name)
         if (language_name_is_utf8 (language_name)) {
                 name = g_strdup (language_name);
         } else {
-                name = g_strdup_printf ("%s.utf8", language_name);
+                name = g_strdup_printf ("%s.UTF-8", language_name);
 
                 if (!language_name_is_utf8 (name)) {
                         g_free (name);
@@ -482,7 +482,7 @@ select_dirs (const struct dirent *dirent
                                 struct stat st;
                                 char       *path;
 
-                                path = g_build_filename (GNOMELOCALEDIR, dirent->d_name, NULL);
+                                path = g_build_filename ("/usr/share/locale", dirent->d_name, NULL);
                                 if (g_stat (path, &st) == 0) {
                                         mode = st.st_mode;
                                 }
@@ -502,7 +502,7 @@ collect_locales_from_directory (void)
         int             ndirents;
         int             cnt;
 
-        ndirents = scandir (GNOMELOCALEDIR, &dirents, select_dirs, alphasort);
+        ndirents = scandir ("/usr/share/locale", &dirents, select_dirs, alphasort);
 
         for (cnt = 0; cnt < ndirents; ++cnt) {
                 add_locale (dirents[cnt]->d_name);
