--- programs/luit/luit.c.orig	Thu Apr  8 05:14:16 2004
+++ programs/luit/luit.c	Thu Apr  8 05:20:18 2004
@@ -545,9 +545,11 @@
 #endif
     installHandler(SIGCHLD, sigchldHandler);
 
+/*  Disabled, appears to break luit.
     rc = copyTermios(0, pty);
     if(rc < 0)
         FatalError("Couldn't copy terminal settings\n");
+*/
 
     rc = setRawTermios();
     if(rc < 0)
