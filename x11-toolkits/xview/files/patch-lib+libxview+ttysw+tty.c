--- lib/libxview/ttysw/tty.c.orig	Thu Oct 16 18:55:36 2003
+++ lib/libxview/ttysw/tty.c	Thu Oct 16 18:58:46 2003
@@ -534,7 +534,7 @@
 tty_quit_on_death(client, pid, status, rusage)
     caddr_t         client;
     int             pid;
-#ifndef SVR4
+#if !(defined(BSD4_4) || defined(SVR4))
     union wait     *status;
 #else
     int     *status;
@@ -586,7 +586,7 @@
 tty_handle_death(tty_folio_private, pid, status, rusage)
     Ttysw_folio     tty_folio_private;
     int             pid;
-#ifndef SVR4
+#if !(defined(BSD4_4) || defined(SVR4))
     union wait     *status;
 #else
     int     *status;
