--- clients/textedit/textedit.c.orig	2005-03-28 06:39:35.000000000 -0800
+++ clients/textedit/textedit.c	2013-09-17 23:16:22.050879918 -0700
@@ -12,7 +12,7 @@
  */
 
 #include <sys/param.h> /* MAXPATHLEN (include types.h if removed) */
-#ifndef __CYGWIN__
+#if !defined(__CYGWIN__) && !defined(__FreeBSD__)
 #include <sys/dir.h>   /* MAXNAMLEN */
 #else
 #include <dirent.h>
@@ -45,7 +45,7 @@
 long	textsw_store_file();
 */
 char	*getwd();
-#if !defined(__linux__) && !defined(__CYGWIN__)
+#if !defined(__linux__) && !defined(__CYGWIN__) && !defined(__FreeBSD__)
 char *sprintf();
 #endif
 void	frame_cmdline_help();
@@ -257,7 +257,7 @@
 	char		*attr_string;
 
 	if (handling_signal)
-	    return;
+	    return 0;
 	icon_text[0] = '\0';
 	ptr = icon_text;
 	for (attrs = attributes; *attrs; attrs = attr_next(attrs)) {
@@ -824,10 +824,10 @@
 	 * Setup signal handlers.
 	 */
 	(void)notify_set_signal_func(base_frame, mysigproc, SIGINT,  NOTIFY_ASYNC);
-#if !(defined(__linux__) || defined(__CYGWIN__)) || defined(SIGXCPU)
+#if !(defined(__linux__) || defined(__CYGWIN__) || defined(__FreeBSD__)) || defined(SIGXCPU)
 	(void)notify_set_signal_func(base_frame, mysigproc, SIGXCPU, NOTIFY_ASYNC);
 #endif
-#if !(defined(__linux__) || defined(__CYGWIN__)) || defined(SIGBUS)
+#if !(defined(__linux__) || defined(__CYGWIN__) || defined(__FreeBSD__)) || defined(SIGBUS)
 	(void)notify_set_signal_func(base_frame, mysigproc, SIGBUS,  NOTIFY_ASYNC);
 #endif
 	(void)notify_set_signal_func(base_frame, mysigproc, SIGHUP,  NOTIFY_ASYNC);
@@ -915,7 +915,7 @@
 	char			 name_to_use[MAXNAMLEN];
 	int			 pid = getpid();
 	int			 was_SIGILL = (sig == SIGILL);
-#if !defined(__linux__) && !defined(__CYGWIN__)
+#if !defined(__linux__) && !defined(__CYGWIN__) && !defined(__FreeBSD__)
 	struct sigvec vec;
 #else
 	struct sigaction vec;
@@ -978,7 +978,7 @@
 #ifndef lint
 	    char	dummy, *bad_ptr = 0;
 	    /* (void)signal(SIGSEGV, SIG_DFL);	/* Make sure 0 deref dumps. */
-#if !defined(__linux__) && !defined(__CYGWIN__)
+#if !defined(__linux__) && !defined(__CYGWIN__) && !defined(__FreeBSD__)
 	    vec.sv_handler = SIG_DFL;
 	    vec.sv_mask = vec.sv_onstack = 0;
 	    sigvec(SIGSEGV, &vec, 0);
@@ -1001,7 +1001,7 @@
 #endif
 	} else {
 	    /* (void)signal(SIGILL, SIG_DFL);	/* Make sure abort() dumps. */
-#if !defined(__linux__) && !defined(__CYGWIN__)
+#if !defined(__linux__) && !defined(__CYGWIN__) && !defined(__FreeBSD__)
             vec.sv_handler = SIG_DFL; 
 	    vec.sv_mask = vec.sv_onstack = 0; 
             sigvec(SIGILL, &vec, 0);
@@ -1029,7 +1029,6 @@
 /*
  * Misc. utilities
  */
-static
 die(msg1, msg2, msg3)
 	char	*msg1, *msg2, *msg3;
 {
