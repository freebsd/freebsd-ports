--- konsole/src/TEPty.C	Tue Oct  3 14:57:30 2000
+++ konsole/src/TEPty.C.new	Thu Nov  2 17:51:30 2000
@@ -225,7 +225,7 @@
 #ifdef HAVE_UTEMPTER
   removeLineFromUtmp(ttynam, fd);
 #elif defined(USE_LOGIN)
-  char *tty_name=ttyname(0);
+  char *tty_name=ttyname(fd);
   if (tty_name)
         logout(tty_name);
 #endif
