--- src/logging.c.orig	2014-12-09 13:47:18.000000000 -0800
+++ src/logging.c	2014-12-09 13:47:35.000000000 -0800
@@ -82,7 +82,8 @@
     else if (sscanf(pty, "pts/%d", &i) == 1)
 	sprintf(ut_id, "vt%02x", (i & 0xff));	/* sysv naming */
 #endif
-    else if (STRNCMP(pty, "pty", 3) && STRNCMP(pty, "tty", 3)) {
+    else if (STRNCMP(pty, "pty", 3) && STRNCMP(pty, "tty", 3) &&
+		STRNCMP(pty, "pts/", 4)) {
 	xvt_print_error("can't parse tty name \"%s\"", pty);
 	return;
     }
@@ -137,7 +138,9 @@
     STRNCPY(utx->ut_user, (pwent && pwent->pw_name) ? pwent->pw_name : "?",
 	    sizeof(utx->ut_user));
     STRNCPY(utx->ut_id, ut_id, sizeof(utx->ut_id));
+#if 0
     utx->ut_session = getsid(0);
+#endif
     utx->ut_tv.tv_sec = time(NULL);
     utx->ut_tv.tv_usec = 0;
     utx->ut_pid = r->h->cmd_pid;
@@ -202,7 +205,7 @@
 	xvt_update_wtmp(XVT_WTMP_FILE, ut);
 #  endif
 # endif
-# ifdef HAVE_STRUCT_UTMPX
+# if 0
 	updwtmpx(XVT_WTMPX_FILE, utx);
 # endif
     }
@@ -254,7 +257,9 @@
     if ((tmputx = getutxid(utx)))	/* position to entry in utmp file */
 	utx = tmputx;
     utx->ut_type = DEAD_PROCESS;
+#if 0
     utx->ut_session = getsid(0);
+#endif
     utx->ut_tv.tv_sec = time(NULL);
     utx->ut_tv.tv_usec = 0;
 #endif
@@ -274,7 +279,7 @@
 	xvt_update_wtmp(XVT_WTMP_FILE, ut);
 #  endif
 # endif
-# ifdef HAVE_STRUCT_UTMPX
+# if 0
 	updwtmpx(XVT_WTMPX_FILE, utx);
 # endif
     }
