--- programs/luit/luit.c	Fri Mar  5 01:48:51 2004
+++ /tmp/luit/luit.c	Sun Jul 18 09:01:22 2004
@@ -45,6 +45,8 @@
 #include "charset.h"
 #include "iso2022.h"
 
+static int p2c_waitpipe[2];
+static int c2p_waitpipe[2];
 static Iso2022Ptr inputState = NULL, outputState = NULL;
 
 static char *child_argv0 = NULL;
@@ -462,6 +464,8 @@
         exit(1);
     }
 
+    pipe(p2c_waitpipe);
+    pipe(c2p_waitpipe);
     pid = fork();
     if(pid < 0) {
         perror("Couldn't fork");
@@ -470,8 +474,12 @@
 
     if(pid == 0) {
         close(pty);
+	close(p2c_waitpipe[1]);
+	close(c2p_waitpipe[0]);
         child(line, path, child_argv);
     } else {
+	close(p2c_waitpipe[0]);
+	close(c2p_waitpipe[1]);
         free(child_argv);
         free(path);
         free(line);
@@ -486,6 +494,7 @@
 {
     int tty;
     int pgrp;
+    char tmp[10];
 
     close(0);
     close(1);
@@ -501,6 +510,7 @@
         kill(getppid(), SIGABRT);
         exit(1);
     }
+    write(c2p_waitpipe[1],"1",1);
     
     if(tty != 0)
         dup2(tty, 0);
@@ -512,6 +522,9 @@
     if(tty > 2)
         close(tty);
     
+    read(p2c_waitpipe[0],tmp,1);
+    close(c2p_waitpipe[1]);
+    close(p2c_waitpipe[0]);
     execvp(path, argv);
     perror("Couldn't exec");
     exit(1);
@@ -535,7 +548,9 @@
     int i;
     int val;
     int rc;
+    char tmp[10];
 
+    read(c2p_waitpipe[0],tmp,1);
     if(verbose) {
         reportIso2022(outputState);
     }
@@ -564,6 +579,9 @@
 
     setWindowSize(0, pty);
 
+    write(p2c_waitpipe[1],"1",1);
+    close(c2p_waitpipe[0]);
+    close(p2c_waitpipe[1]);
     for(;;) {
         rc = waitForInput(0, pty);
 
