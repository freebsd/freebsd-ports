--- src/terminal-screen.c.orig	Thu Mar  3 15:13:08 2005
+++ src/terminal-screen.c	Wed Mar 16 03:11:08 2005
@@ -246,18 +246,18 @@
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
-      "\\<(mailto:)?[a-z0-9][a-z0-9.-]*@[a-z0-9][a-z0-9-]*(\\.[a-z0-9][a-z0-9-]*)+\\>", FLAVOR_MAILTO);
+      "[[:<:]](mailto:)?[a-z0-9][a-z0-9.-]*@[a-z0-9][a-z0-9-]*(\\.[a-z0-9][a-z0-9-]*)+[[:>:]]", FLAVOR_MAILTO);
 	  
   terminal_widget_match_add (screen->priv->term,
-      "\\<news:[-A-Z\\^_a-z{|}~!\"#$%&'()*+,./0-9;:=?`]+@[" HOSTCHARS ".]+(:[0-9]+)?\\>", FLAVOR_AS_IS);
+      "[[:<:]]news:[-A-Z\\^_a-z{|}~!\"#$%&'()*+,./0-9;:=?`]+@[" HOSTCHARS ".]+(:[0-9]+)?[[:>:]]", FLAVOR_AS_IS);
 
 
   terminal_screen_setup_dnd (screen);
