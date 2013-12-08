--- gnome-pty-helper/gnome-utmp.c.orig	Sat Oct 28 23:15:53 2006
+++ gnome-pty-helper/gnome-utmp.c	Sat Oct 28 23:15:40 2006
@@ -258,10 +258,18 @@ write_logout_record (char *login_name, v
 #endif
 
 	if (utmp)
+#if defined(__FreeBSD__)
+		logout (put.ut_line);
+#else
 		update_utmp (&put);
+#endif
 
 	if (wtmp)
+#if defined(__FreeBSD__)
+		logwtmp (put.ut_line, "", "");
+#else
 		update_wtmp (WTMP_OUTPUT_FILENAME, &put);
+#endif
 
 	free (ut);
 }
@@ -347,10 +355,18 @@ write_login_record (char *login_name, ch
 #    endif
 #endif
 	if (utmp)
+#if defined(__FreeBSD__)
+		login (ut);
+#else
 		update_utmp (ut);
+#endif
 
 	if (wtmp)
+#if defined(__FreeBSD__)
+		logwtmp (ut->ut_line, ut->ut_name, ut->ut_host);
+#else
 		update_wtmp (WTMP_OUTPUT_FILENAME, ut);
+#endif
 
 	if (lastlog)
 		update_lastlog(login_name, ut);
