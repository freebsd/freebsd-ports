--- ./terminal/terminal-preferences-dialog.c.orig	2011-06-21 20:32:31.000000000 +0000
+++ ./terminal/terminal-preferences-dialog.c	2012-12-23 22:37:02.000000000 +0000
@@ -96,9 +96,6 @@
                                     "shortcuts-no-mnemonics", "shortcuts-no-menukey",
                                     "binding-backspace", "binding-delete",
                                     "background-mode", "background-image-style"
-#if TERMINAL_HAS_ANTI_ALIAS_SETTING
-                                    , "font-anti-alias"
-#endif
                                     };
   const gchar      *props_color[] =  { "color-foreground", "color-cursor",
                                        "color-background", "tab-activity-color",
@@ -167,13 +164,6 @@
   BIND_PROPERTIES ("tab-activity-timeout", "value");
   BIND_PROPERTIES ("background-darkness", "value");
 
-#if !TERMINAL_HAS_ANTI_ALIAS_SETTING
-  /* hide anti alias setting */
-  object = gtk_builder_get_object (GTK_BUILDER (dialog), "font-anti-alias");
-  terminal_return_if_fail (G_IS_OBJECT (object));
-  gtk_widget_hide (GTK_WIDGET (object));
-#endif
-
   /* reset comparibility button */
   object = gtk_builder_get_object (GTK_BUILDER (dialog), "reset-compatibility");
   terminal_return_if_fail (G_IS_OBJECT (object));
