--- l10n_read.c.orig	Fri Nov  7 17:21:25 1997
+++ l10n_read.c	Mon Oct 21 03:29:17 2002
@@ -18,15 +18,17 @@
 #include	"l10n_props.h"
 
 
-#define	MAX_LINE_LENGTH		256
+#define	MAX_LINE_LENGTH		2560
 
 #define	NAME_SEPARATOR		'='
 #define	FIELD_SEPARATOR		'|'
 #define	ITEM_SEPARATOR		';'
 
 
+#if !defined(__FreeBSD__)
 extern char	*malloc();
 extern char	*calloc();
+#endif
 
 
 /*
@@ -72,8 +74,9 @@
 	/*  
 	 * Find path for localization configuration files under
 	 * $OPENWINHOME/share/locale/<locale>/props
+ 	 * $OPENWINHOME/lib/X11/locale/<locale>/props
 	 */
-	sprintf(fullpath, "%s/share/locale/%s/props/%s",
+	sprintf(fullpath, "%s/lib/X11/locale/%s/props/%s",
 		getenv("OPENWINHOME"), locale, file_name);
 
 	if ((config_file = fopen(fullpath, "r")) == NULL)
