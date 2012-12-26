--- ./terminal/terminal-private.h.orig	2011-06-21 20:32:31.000000000 +0000
+++ ./terminal/terminal-private.h	2012-12-23 22:39:59.000000000 +0000
@@ -24,14 +24,6 @@
 
 G_BEGIN_DECLS
 
-/* whether anti-alias is enabled in the application. this settings will
- * be removed in vte 1.0 and there is no other way to set this. */
-#ifndef NDEBUG
-#define TERMINAL_HAS_ANTI_ALIAS_SETTING (FALSE)
-#else
-#define TERMINAL_HAS_ANTI_ALIAS_SETTING (TRUE)
-#endif
-
 /* returns true if string contains text */
 #define IS_STRING(string) ((string) != NULL && *(string) != '\0')
 
