--- render/font.c.orig	Sat Aug 26 22:15:51 2006
+++ render/font.c	Tue Sep 12 21:14:46 2006
@@ -92,6 +92,8 @@
 #ifdef USE_PANGO
     guchar *tmp_string = NULL;
     gint tmp_int;
+    gchar *locale, *p;
+    PangoFontMetrics *metrics;
 #endif /* USE_PANGO */
 
     if (!(pat = XftNameParse(fontstring)))
@@ -135,13 +137,12 @@
     }
 
     /* based on gtkmain.c gtk_get_default_language() */
-    gchar *locale, *p;
     locale = g_strdup(setlocale(LC_CTYPE, NULL));
     if ((p = strchr(locale, '.')))
         *p = '\0';
     if ((p = strchr(locale, '@')))
         *p = '\0';
-    PangoFontMetrics *metrics = 
+    metrics = 
         pango_context_get_metrics(context, out->pango_font_description,
                                   pango_language_from_string(locale));
     out->pango_ascent = pango_font_metrics_get_ascent(metrics);
