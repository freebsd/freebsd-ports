--- lib/libxview/textsw/txt_e_menu.c.orig	2012-02-04 10:33:31.397319914 -0800
+++ lib/libxview/textsw/txt_e_menu.c	2012-02-04 10:37:28.681263979 -0800
@@ -19,7 +19,7 @@
  *  3. $(HOME)/.text_extras_menu{.<locale>} (home dir),
  *  4. locale sensitive system default
  *		("$OPENWINHOME/lib/locale/<locale>/XView/.text_extras_menu")
- *  4. fall back to SunView1 ("/usr/lib/.text_extras_menu")
+ *  4. fall back to SunView1 ("/usr/local/lib/.text_extras_menu")
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
@@ -145,17 +147,25 @@
 
 /*#ifdef notdef*/
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
+
 /*#endif*/
 #ifndef OPENWINHOME_DEFAULT
     }
 #endif
 
     /* Giving up, try with ancient way (SunView1) */
-    (void) sprintf(tmp, "/usr/lib/.%s", EXTRASMENU);
+    (void) sprintf(tmp, "/usr/local/lib/.%s", EXTRASMENU);
     result = xv_strsave(tmp);
 
 found:
@@ -639,7 +649,6 @@
 /*
  * Are there any shell meta-characters in string s?
  */
-static
 any_shell_meta_e_menu(s)
     register char  *s;
 {
