--- lib/libxview/sel/sel_agent.c.orig	2005-03-28 06:41:13.000000000 -0800
+++ lib/libxview/sel/sel_agent.c	2012-02-03 09:06:12.722830476 -0800
@@ -33,10 +33,10 @@
 #include <stdio.h>
 /*
  * The following header file provides fd_set compatibility with SunOS for
- * Ultrix
+ * Ultrix and provides howmany() for newer BSDs
  */
 #include <xview_private/ultrix_cpt.h>
-#if defined(SVR4) || defined(__linux__) || defined(__CYGWIN__)
+#if defined(SVR4) || defined(__linux__) || defined(__CYGWIN__) || (defined(BSD4_4) || defined(SVR4))
 #include <stdlib.h>
 #include <unistd.h>
 #endif /* SVR4 */
@@ -68,7 +68,7 @@
 static void     selection_agent_do_function();
 static Atom 	get_atom();
 static Seln_attribute save_atom();
-
+static int	waitforReadableTimeout();
 
 Xv_private Seln_result seln_convert_request_to_property();
 /* called by seln_svc.c
@@ -314,7 +314,9 @@
     struct stat     stat_buf;
     int             count, size;
     char           *destp;
-#ifndef __CYGWIN__
+#if (defined(BSD) && (BSD >= 199306))
+    extern off_t    lseek();
+#elif !defined __CYGWIN__)
     extern long     lseek();
 #endif
     if (fstat(fd, &stat_buf) != 0) {
