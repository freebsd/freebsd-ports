--- ./lib/libxview/file_chooser/file_list.c.orig	Tue Jun 29 07:17:56 1993
+++ ./lib/libxview/file_chooser/file_list.c	Sat Apr  1 18:25:23 2000
@@ -23,6 +23,9 @@ static char     sccsid[] = "@(#)file_lis
 #include <xview_private/flist_impl.h>
 #include <xview_private/portable.h>
 
+#ifdef __FreeBSD__
+#include <regex.h>
+#endif
 
 
 /* X bitmaps for default glyphs */
@@ -41,6 +44,7 @@ static int		go_down_one_directory();
 static int		flist_list_notify();
 static int		validate_new_directory();
 static void		flist_new_dir();
+static int		flist_match_regex();
 
 #if defined(__STDC__) || defined(__cplusplus) || defined(c_plusplus)
 static void	flist_error(File_list_private *private, char *format, ...);
@@ -521,7 +525,11 @@ file_list_destroy ( public, status )
     if (status == DESTROY_CLEANUP) {
 	xv_free_ref( private->directory );
 	xv_free_ref( private->regex_pattern );
+#ifndef __FreeBSD__
 	xv_free_ref( private->regex_compile );
+#else
+	xv_free_regex_t( (regex_t *)private->regex_compile );
+#endif
 	xv_free_ref( private->dotdot_string );
 	if ( private->dir_ptr )
 	    (void) closedir( private->dir_ptr );
@@ -1174,14 +1182,16 @@ static char	*compile();
 static int 	step();
 #endif /* SVR4 */
 
-
+#ifndef __FreeBSD__
 #include <regexp.h>
+#endif
 
 
 static void
 flist_compile_regex( private )
      File_list_private *private;
 {
+#ifndef __FreeBSD__
     char compile_buf[MAXPATHLEN+1];
     char *end_ptr;
     size_t num_bytes;
@@ -1197,6 +1207,17 @@ flist_compile_regex( private )
     xv_free_ref( private->regex_compile );
     private->regex_compile = xv_alloc_n(char, num_bytes);
     (void) XV_BCOPY(compile_buf, private->regex_compile, num_bytes);
+#else
+    regex_t *compile_buf = malloc(sizeof(regex_t));
+    if (compile_buf == NULL){
+      fprintf(stderr, "Couldn't allocate compile buffer\n");
+      exit(-1);
+    } 
+    regcomp(compile_buf, private->regex_pattern, 0);
+    xv_free_regex_t((regex_t *)private->regex_compile);
+    private->regex_compile = (char *)compile_buf;
+#endif
+
 } 
 
 
@@ -1205,7 +1226,11 @@ flist_match_regex( s, private )
      char *s;
      File_list_private *private;
 {
+#ifndef __FreeBSD__
     return step(s, private->regex_compile);
+#else
+    return !regexec((regex_t *)private->regex_compile, s, 0, NULL, 0);
+#endif
 }
 
 /****************************************************************************/
