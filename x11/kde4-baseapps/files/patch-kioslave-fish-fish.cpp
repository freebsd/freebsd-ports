--- kioslave/fish/fish.cpp.orig
+++ kioslave/fish/fish.cpp  
@@ -302,5 +302,5 @@
 void fishProtocol::openConnection() {
 static int open_pty_pair(int fd[2])
 {
-#if defined(HAVE_TERMIOS_H) && defined(HAVE_GRANTPT)
+#if defined(HAVE_TERMIOS_H) && defined(HAVE_GRANTPT) && !defined (HAVE_OPENPTY)
 /** with kind regards to The GNU C Library
 Reference Manual for Version 2.2.x of the GNU C Library */
