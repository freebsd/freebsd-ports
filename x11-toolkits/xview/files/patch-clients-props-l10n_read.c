--- clients/props/l10n_read.c.orig	2012-02-07 19:44:47.873072262 -0800
+++ clients/props/l10n_read.c	2012-02-07 19:54:04.282770082 -0800
@@ -25,7 +25,7 @@
 #define	ITEM_SEPARATOR		';'
 
 
-#if !defined(__linux__) && !defined(__CYGWIN__)
+#if !defined(__linux__) && !defined(__CYGWIN__) && !defined(__FreeBSD__)
 #ifndef ultrix
 extern char	*malloc();
 #endif
