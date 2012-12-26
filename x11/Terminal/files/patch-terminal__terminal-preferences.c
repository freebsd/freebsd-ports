--- ./terminal/terminal-preferences.c.orig	2011-06-21 20:32:31.000000000 +0000
+++ ./terminal/terminal-preferences.c	2012-12-23 22:38:40.000000000 +0000
@@ -101,9 +101,6 @@
   PROP_COMMAND_UPDATE_RECORDS,
   PROP_COMMAND_LOGIN_SHELL,
   PROP_FONT_ALLOW_BOLD,
-#if TERMINAL_HAS_ANTI_ALIAS_SETTING
-  PROP_FONT_ANTI_ALIAS,
-#endif
   PROP_FONT_NAME,
   PROP_MISC_ALWAYS_SHOW_TABS,
   PROP_MISC_BELL,
@@ -980,18 +977,6 @@
                                                          TRUE,
                                                          EXO_PARAM_READWRITE));
 
-#if TERMINAL_HAS_ANTI_ALIAS_SETTING
-  /**
-   * TerminalPreferences:font-anti-alias:
-   **/
-  g_object_class_install_property (gobject_class,
-                                   PROP_FONT_ANTI_ALIAS,
-                                   g_param_spec_boolean ("font-anti-alias",
-                                                         "font-anti-alias",
-                                                         "FontAntiAlias",
-                                                         TRUE,
-                                                         EXO_PARAM_READWRITE));
-#endif
 
   /**
    * TerminalPreferences:font-name:
