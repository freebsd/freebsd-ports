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
@@ -352,7 +352,7 @@ add_locale (const char *language_name)
         if (language_name_is_utf8 (language_name)) {
                 name = g_strdup (language_name);
         } else {
-                name = g_strdup_printf ("%s.utf8", language_name);
+                name = g_strdup_printf ("%s.UTF-8", language_name);
 
                 if (!language_name_is_utf8 (name)) {
                         g_free (name);
