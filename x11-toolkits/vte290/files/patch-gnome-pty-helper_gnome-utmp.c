--- gnome-pty-helper/gnome-utmp.c.orig	2012-03-24 17:30:46.000000000 -0400
+++ gnome-pty-helper/gnome-utmp.c	2012-03-24 17:30:25.000000000 -0400
@@ -152,7 +152,7 @@ update_wtmp (char *file, UTMP *putmp)
 #endif /* !HAVE_GETUTMPX */
 
 
-#if defined(HAVE_GETUTMPX)
+#if defined(HAVE_GETUTMPX) || defined(HAVE_GETUTXID)
 static void
 update_utmp (UTMP *ut)
 {
