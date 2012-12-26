--- ./terminal/terminal-screen.c.orig	2011-06-21 20:32:31.000000000 +0000
+++ ./terminal/terminal-screen.c	2012-12-23 22:42:46.000000000 +0000
@@ -285,7 +285,6 @@
                     "swapped-signal::notify::color-palette15", G_CALLBACK (terminal_screen_update_colors), screen,
                     "swapped-signal::notify::color-palette16", G_CALLBACK (terminal_screen_update_colors), screen,
                     "swapped-signal::notify::font-allow-bold", G_CALLBACK (terminal_screen_update_font), screen,
-                    "swapped-signal::notify::font-anti-alias", G_CALLBACK (terminal_screen_update_font), screen,
                     "swapped-signal::notify::font-name", G_CALLBACK (terminal_screen_update_font), screen,
                     "swapped-signal::notify::misc-bell", G_CALLBACK (terminal_screen_update_misc_bell), screen,
                     "swapped-signal::notify::misc-cursor-blinks", G_CALLBACK (terminal_screen_update_misc_cursor_blinks), screen,
@@ -848,10 +847,6 @@
 static void
 terminal_screen_update_font (TerminalScreen *screen)
 {
-#if TERMINAL_HAS_ANTI_ALIAS_SETTING
-  VteTerminalAntiAlias antialias;
-  gboolean             font_anti_alias;
-#endif
   gboolean             font_allow_bold;
   gchar               *font_name;
 
@@ -861,9 +856,6 @@
 
   g_object_get (G_OBJECT (screen->preferences),
                 "font-allow-bold", &font_allow_bold,
-#if TERMINAL_HAS_ANTI_ALIAS_SETTING
-                "font-anti-alias", &font_anti_alias,
-#endif
                 "font-name", &font_name,
                 NULL);
 
@@ -871,15 +863,7 @@
     {
       vte_terminal_set_allow_bold (VTE_TERMINAL (screen->terminal), font_allow_bold);
 
-#if TERMINAL_HAS_ANTI_ALIAS_SETTING
-      antialias = font_anti_alias
-                ? VTE_ANTI_ALIAS_USE_DEFAULT
-                : VTE_ANTI_ALIAS_FORCE_DISABLE;
-      vte_terminal_set_font_from_string_full (VTE_TERMINAL (screen->terminal),
-                                              font_name, antialias);
-#else
       vte_terminal_set_font_from_string (VTE_TERMINAL (screen->terminal), font_name);
-#endif
 
       g_free (font_name);
     }
