--- lib/libxview/file_chooser/file_list.c.orig	2005-03-28 06:40:42.000000000 -0800
+++ lib/libxview/file_chooser/file_list.c	2012-02-02 17:05:39.791400764 -0800
@@ -23,6 +23,9 @@
 #include <xview_private/flist_impl.h>
 #include <xview_private/portable.h>
 
+#ifdef __FreeBSD__
+#include <regex.h>
+#endif
 
 
 /* X bitmaps for default glyphs */
@@ -41,6 +44,7 @@
 static int		flist_list_notify();
 static int		validate_new_directory();
 static void		flist_new_dir();
+static int		flist_match_regex();
 
 #if defined(__STDC__) || defined(__cplusplus) || defined(c_plusplus)
 static void	flist_error(File_list_private *private, char *format, ...);
@@ -530,7 +534,11 @@
 	if (private->regex_compile != NULL && private->regex_compile->allocated)
 		xv_free_ref( private->regex_compile->buffer);
 #endif
+#ifdef __FreeBSD__
+        xv_free_regex_t( private->regex_compile );
+#else
 	xv_free_ref( private->regex_compile );
+#endif
 	xv_free_ref( private->dotdot_string );
 	if ( private->dir_ptr )
 	    (void) closedir( private->dir_ptr );
@@ -1184,12 +1192,15 @@
 static int 	step();
 #endif /* SVR4 */
 
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
@@ -1205,6 +1216,17 @@
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
+    xv_free_regex_t(private->regex_compile);
+    private->regex_compile = (char *)compile_buf;
+#endif
+
 } 
 
 
@@ -1213,7 +1235,11 @@
      char *s;
      File_list_private *private;
 {
+#ifndef __FreeBSD__
     return step(s, private->regex_compile);
+#else
+    return !regexec((regex_t *)private->regex_compile, s, 0, NULL, 0);
+#endif
 }
 
 #else /* __linux__ */
