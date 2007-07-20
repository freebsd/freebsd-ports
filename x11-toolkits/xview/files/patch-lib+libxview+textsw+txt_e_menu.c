--- lib/libxview/textsw/txt_e_menu.c.orig	Tue Jun 29 00:17:42 1993
+++ lib/libxview/textsw/txt_e_menu.c	Sat Jun 30 20:13:46 2007
@@ -76,6 +76,8 @@
 static	int      Nargs;
 static	char	*check_filename_locale();
 
+static any_shell_meta();
+
 extern int      EXTRASMENU_FILENAME_KEY;
 
 Pkg_private char *
@@ -138,10 +140,17 @@
 
 #ifdef notdef
 	/* Gee, still?... We will try the old fashioned way */
+	/* If it is never defined, EXTRASMENU is set to text_extras_menu
+	   see top of this file ... */
         (void) sprintf(tmp, "%s/lib/.%s",
 		       filename, EXTRASMENU);
 	if ((result = check_filename_locale(NULL, tmp, 1)) != NULL)
 		goto found;
+	/* EXTRASMENU is absolute specified as normally done
+	   during  compile time option -DEXTRASMENU="\"$(TEXT_EXTRAS_MENU)\" */
+	(void) sprintf(tmp, "%s", EXTRASMENU);
+	if ((result = check_filename_locale(NULL, tmp, 1)) != NULL)
+	    goto found;
 #endif
     }
 
