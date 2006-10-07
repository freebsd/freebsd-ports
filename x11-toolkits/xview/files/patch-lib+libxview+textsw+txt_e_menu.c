--- lib/libxview/textsw/txt_e_menu.c.orig	Thu Oct  5 19:18:11 2006
+++ lib/libxview/textsw/txt_e_menu.c	Thu Oct  5 20:03:45 2006
@@ -19,7 +19,7 @@
  *  3. $(HOME)/.text_extras_menu{.<locale>} (home dir),
  *  4. locale sensitive system default
  *		("$OPENWINHOME/lib/locale/<locale>/XView/.text_extras_menu")
- *  4. fall back to SunView1 ("/usr/lib/.text_extras_menu")
+ *  4. fall back to SunView1 ("/usr/X11R6/lib/.text_extras_menu")
  *
  * Always try locale specific name first, if not there, try without
  * locale name.  In the #4, we will fall back to the "C" locale.
@@ -76,6 +76,8 @@
 static	int      Nargs;
 static	char	*check_filename_locale();
 
+static any_shell_meta();
+
 extern int      EXTRASMENU_FILENAME_KEY;
 
 Pkg_private char *
@@ -138,15 +140,22 @@
 
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
 
     /* Giving up, try with ancient way (SunView1) */
-    (void) sprintf(tmp, "/usr/lib/.%s", EXTRASMENU);
+    (void) sprintf(tmp, "/usr/X11R6/lib/.%s", EXTRASMENU);
     result = xv_strsave(tmp);
 
 found:
