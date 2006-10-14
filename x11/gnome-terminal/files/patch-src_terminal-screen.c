--- src/terminal-screen.c.orig	Wed May 17 17:02:36 2006
+++ src/terminal-screen.c	Thu May 18 15:30:27 2006
@@ -278,22 +278,22 @@ terminal_screen_init (TerminalScreen *sc
 #define URLPATH   "/[" PATHCHARS "]*[^]'.}>) \t\r\n,\\\"]"
 
   terminal_widget_match_add (screen->priv->term,
-			     "\\<" SCHEME "//(" USER "@)?[" HOSTCHARS ".]+"
-			     "(:[0-9]+)?(" URLPATH ")?\\>/?", FLAVOR_AS_IS);
+			     "[[:<:]]" SCHEME "//(" USER "@)?[" HOSTCHARS ".]+"
+			     "(:[0-9]+)?(" URLPATH ")?[[:>:]]/?", FLAVOR_AS_IS);
 
   terminal_widget_match_add (screen->priv->term,
-			     "\\<(www|ftp)[" HOSTCHARS "]*\\.[" HOSTCHARS ".]+"
-			     "(:[0-9]+)?(" URLPATH ")?\\>/?",
+			     "[[:<:]](www|ftp)[" HOSTCHARS "]*\\.[" HOSTCHARS ".]+"
+			     "(:[0-9]+)?(" URLPATH ")?[[:>:]]/?",
 			     FLAVOR_DEFAULT_TO_HTTP);
 
   terminal_widget_match_add (screen->priv->term,
-			     "\\<(mailto:)?[a-z0-9][a-z0-9.-]*@[a-z0-9]"
-			     "[a-z0-9-]*(\\.[a-z0-9][a-z0-9-]*)+\\>",
+			     "[[:<:]](mailto:)?[a-z0-9][a-z0-9.-]*@[a-z0-9]"
+			     "[a-z0-9-]*(\\.[a-z0-9][a-z0-9-]*)+[[:>:]]",
 			     FLAVOR_EMAIL);
 
   terminal_widget_match_add (screen->priv->term,
-			     "\\<news:[-A-Z\\^_a-z{|}~!\"#$%&'()*+,./0-9;:=?`]+"
-			     "@[" HOSTCHARS ".]+(:[0-9]+)?\\>", FLAVOR_AS_IS);
+			     "[[:<:]]news:[-A-Z\\^_a-z{|}~!\"#$%&'()*+,./0-9;:=?`]+"
+			     "@[" HOSTCHARS ".]+(:[0-9]+)?[[:>:]]", FLAVOR_AS_IS);
 
   terminal_screen_setup_dnd (screen);
 
