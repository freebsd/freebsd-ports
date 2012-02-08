--- lib/libxview/ttysw/tty.c.orig	2005-03-28 06:41:31.000000000 -0800
+++ lib/libxview/ttysw/tty.c	2012-02-03 11:42:08.176574457 -0800
@@ -534,7 +534,7 @@
 tty_quit_on_death(client, pid, status, rusage)
     caddr_t         client;
     int             pid;
-#if !defined SVR4 && !defined __CYGWIN__
+#if !defined SVR4 && !defined __CYGWIN__ && !defined __FreeBSD__
     union wait     *status;
 #else
     int     *status;
@@ -592,7 +592,7 @@
 tty_handle_death(tty_folio_private, pid, status, rusage)
     Ttysw_folio     tty_folio_private;
     int             pid;
-#if !defined SVR4 && !defined __CYGWIN__
+#if !defined SVR4 && !defined __CYGWIN__ && !defined __FreeBSD__
     union wait     *status;
 #else
     int     *status;
