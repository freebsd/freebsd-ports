--- lib/libxview/sel/sel_agent.c.orig	Fri Oct 17 00:27:07 2003
+++ lib/libxview/sel/sel_agent.c	Fri Oct 17 00:55:00 2003
@@ -28,10 +28,10 @@
 #include <stdio.h>
 /*
  * The following header file provides fd_set compatibility with SunOS for
- * Ultrix
+ * Ultrix and provides howmany() for newer BSDs
  */
 #include <xview_private/ultrix_cpt.h>
-#ifdef SVR4
+#if (defined(BSD4_4) || defined(SVR4))
 #include <stdlib.h>
 #include <unistd.h>
 #endif
@@ -63,7 +63,7 @@
 static void     selection_agent_do_function();
 static Atom 	get_atom();
 static Seln_attribute save_atom();
-
+static int	waitforReadableTimeout();
 
 Xv_private Seln_result seln_convert_request_to_property();
 /* called by seln_svc.c
@@ -309,7 +309,11 @@
     struct stat     stat_buf;
     int             count, size;
     char           *destp;
+#if (defined(BSD) && (BSD >= 199306))
+    extern off_t    lseek();
+#else
     extern long     lseek();
+#endif
 
     if (fstat(fd, &stat_buf) != 0) {
 	perror(XV_MSG("Agent couldn't reply about a file"));
