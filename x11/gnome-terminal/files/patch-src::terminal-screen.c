--- src/terminal-screen.c.orig	Thu Nov 18 12:45:11 2004
+++ src/terminal-screen.c	Thu Nov 18 12:46:31 2004
@@ -246,16 +246,16 @@
 #define USER      "[" USERCHARS "]+(:["PASSCHARS "]+)?"
 
   terminal_widget_match_add (screen->priv->term,
-      "\\<(" SCHEME "://(" USER "@)?)[" HOSTCHARS ".]+(:[0-9]+)?"
-      "(/[-A-Za-z0-9_$.+!*(),;:@&=?/~#%]*[^]'.}>) \t\r\n,\\\"])?\\>", FLAVOR_AS_IS);
+      "[[:<:]](" SCHEME "://(" USER "@)?)[" HOSTCHARS ".]+(:[0-9]+)?"
+      "(/[-A-Za-z0-9_$.+!*(),;:@&=?/~#%]*[^]'.}>) \t\r\n,\\\"])?[[:>:]]", FLAVOR_AS_IS);
 
   terminal_widget_match_add (screen->priv->term,
-      "\\<(www|ftp)[" HOSTCHARS "]*\\.[" HOSTCHARS ".]+(:[0-9]+)?"
-      "(/[-A-Za-z0-9_$.+!*(),;:@&=?/~#%]*[^]'.}>) \t\r\n,\\\"])?\\>", FLAVOR_DEFAULT_TO_HTTP);
+      "[[:<:]](www|ftp)[" HOSTCHARS "]*\\.[" HOSTCHARS ".]+(:[0-9]+)?"
+      "(/[-A-Za-z0-9_$.+!*(),;:@&=?/~#%]*[^]'.}>) \t\r\n,\\\"])?[[:>:]]", FLAVOR_DEFAULT_TO_HTTP);
 
   terminal_widget_match_add (screen->priv->term, 
       
-      "\\<(mailto:)?[a-z0-9]+@[a-z0-9][a-z0-9-]*(\\.[a-z0-9][a-z0-9-]*)+\\>", FLAVOR_MAILTO);
+      "[[:<:]](mailto:)?[a-z0-9]+@[a-z0-9][a-z0-9-]*(\\.[a-z0-9][a-z0-9-]*)+[[:>:]]", FLAVOR_MAILTO);
 
   terminal_screen_setup_dnd (screen);
   
