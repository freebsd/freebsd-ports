--- ./main.c.orig	2011-10-09 16:14:51.000000000 +0200
+++ ./main.c	2011-11-18 09:29:46.000000000 +0100
@@ -3312,19 +3312,18 @@
 	 * necessary.  ENXIO is what is normally returned if there is
 	 * no controlling terminal, but some systems (e.g. SunOS 4.0)
 	 * seem to return EIO.  Solaris 2.3 is said to return EINVAL.
-	 * Cygwin returns ENOENT.
+	 * Cygwin returns ENOENT.  FreeBSD can return ENOENT, especially
+	 * if xterm is run within a jail.
 	 */
 #if USE_NO_DEV_TTY
 	no_dev_tty = False;
 #endif
 	if (ttyfd < 0) {
 	    if (tty_got_hung || errno == ENXIO || errno == EIO ||
+		errno == ENOENT ||
 #ifdef ENODEV
 		errno == ENODEV ||
 #endif
-#ifdef __CYGWIN__
-		errno == ENOENT ||
-#endif
 		errno == EINVAL || errno == ENOTTY || errno == EACCES) {
 #if USE_NO_DEV_TTY
 		no_dev_tty = True;
