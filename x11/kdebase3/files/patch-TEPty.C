--- konsole/src/TEPty.C	Sun Feb 18 10:28:28 2001
+++ konsole/src/TEPty.C.new	Fri Feb 23 02:55:58 2001
@@ -238,7 +238,7 @@
 #ifdef HAVE_UTEMPTER
   removeLineFromUtmp(ttynam, fd);
 #elif defined(USE_LOGIN)
-  char *tty_name=ttyname(0);
+  char *tty_name=ttyname(fd);
   if (tty_name)
   {
   	if (strncmp(tty_name, "/dev/", 5) == 0)
