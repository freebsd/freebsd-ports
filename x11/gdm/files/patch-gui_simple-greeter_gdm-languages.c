--- gui/simple-greeter/gdm-languages.c.orig	2010-01-13 16:20:08.000000000 +0000
+++ gui/simple-greeter/gdm-languages.c	2010-01-17 13:10:50.000000000 +0000
@@ -365,7 +365,7 @@ add_locale (const char *language_name,
         if (is_utf8) {
                 name = g_strdup (language_name);
         } else if (utf8_only) {
-                name = g_strdup_printf ("%s.utf8", language_name);
+                name = g_strdup_printf ("%s.UTF-8", language_name);
 
                 language_name_get_codeset_details (name, NULL, &is_utf8);
                 if (is_utf8) {
