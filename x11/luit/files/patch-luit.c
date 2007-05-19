--- luit-1.0.2/luit.c	Wed Nov  8 22:21:35 2006
+++ luit.c	Sun May 20 00:51:20 2007
@@ -45,6 +45,8 @@
 #include "charset.h"
 #include "iso2022.h"
 
+static int p2c_waitpipe[2];
+static int c2p_waitpipe[2];
 static Iso2022Ptr inputState = NULL, outputState = NULL;
 
 static char *child_argv0 = NULL;
@@ -434,17 +436,6 @@
     return 0;
 }
         
-static void
-sigwinchHandler(int sig)
-{
-    sigwinch_queued = 1;
-}
-
-static void
-sigchldHandler(int sig)
-{
-    sigchld_queued = 1;
-}
 
 static int
 condom(int argc, char **argv)
@@ -455,7 +446,6 @@
     char *path;
     char **child_argv;
     int rc;
-    int val;
 
     rc = parseArgs(argc, argv, child_argv0,
                    &path, &child_argv);
@@ -473,30 +463,9 @@
         perror("Couldn't drop priviledges");
         exit(1);
     }
-#ifdef SIGWINCH
-    installHandler(SIGWINCH, sigwinchHandler);
-#endif
-    installHandler(SIGCHLD, sigchldHandler);
-
-    rc = copyTermios(0, pty);
-    if(rc < 0)
-        FatalError("Couldn't copy terminal settings\n");
-
-    rc = setRawTermios();
-    if(rc < 0)
-        FatalError("Couldn't set terminal to raw\n");
-
-    val = fcntl(0, F_GETFL, 0);
-    if(val >= 0) {
-        fcntl(0, F_SETFL, val | O_NONBLOCK);
-    }
-    val = fcntl(pty, F_GETFL, 0);
-    if(val >= 0) {
-        fcntl(pty, F_SETFL, val | O_NONBLOCK);
-    }
-
-    setWindowSize(0, pty);
 
+    pipe(p2c_waitpipe);
+    pipe(c2p_waitpipe);
     pid = fork();
     if(pid < 0) {
         perror("Couldn't fork");
@@ -505,12 +474,12 @@
 
     if(pid == 0) {
         close(pty);
-#ifdef SIGWINCH
-        installHandler(SIGWINCH, SIG_DFL);
-#endif
-        installHandler(SIGCHLD, SIG_DFL);
+	close(p2c_waitpipe[1]);
+	close(c2p_waitpipe[0]);
         child(line, path, child_argv);
     } else {
+	close(p2c_waitpipe[0]);
+	close(c2p_waitpipe[1]);
         free(child_argv);
         free(path);
         free(line);
@@ -525,11 +494,11 @@
 {
     int tty;
     int pgrp;
+    char tmp[10];
 
     close(0);
     close(1);
     close(2);
-
     pgrp = setsid();
     if(pgrp < 0) {
         kill(getppid(), SIGABRT);
@@ -541,6 +510,7 @@
         kill(getppid(), SIGABRT);
         exit(1);
     }
+    write(c2p_waitpipe[1],"1",1);
     
     if(tty != 0)
         dup2(tty, 0);
@@ -552,22 +522,66 @@
     if(tty > 2)
         close(tty);
     
+    read(p2c_waitpipe[0],tmp,1);
+    close(c2p_waitpipe[1]);
+    close(p2c_waitpipe[0]);
     execvp(path, argv);
     perror("Couldn't exec");
     exit(1);
 }
 
+static void
+sigwinchHandler(int sig) {
+    sigwinch_queued = 1;
+}
+
+static void
+sigchldHandler(int sig)
+{
+    sigchld_queued = 1;
+}
+
 void
 parent(int pid, int pty)
 {
     unsigned char buf[BUFFER_SIZE];
     int i;
+    int val;
     int rc;
+    char tmp[10];
 
+    read(c2p_waitpipe[0],tmp,1);
     if(verbose) {
         reportIso2022(outputState);
     }
 
+#ifdef SIGWINCH
+    installHandler(SIGWINCH, sigwinchHandler);
+#endif
+    installHandler(SIGCHLD, sigchldHandler);
+
+    rc = copyTermios(0, pty);
+    if(rc < 0)
+        FatalError("Couldn't copy terminal settings\n");
+
+    rc = setRawTermios();
+    if(rc < 0)
+        FatalError("Couldn't set terminal to raw\n");
+
+    val = fcntl(0, F_GETFL, 0);
+    if(val >= 0) {
+        fcntl(0, F_SETFL, val | O_NONBLOCK);
+    }
+    val = fcntl(pty, F_GETFL, 0);
+    if(val >= 0) {
+        fcntl(pty, F_SETFL, val | O_NONBLOCK);
+    }
+
+    setWindowSize(0, pty);
+
+    write(p2c_waitpipe[1],"1",1);
+    close(c2p_waitpipe[0]);
+    close(p2c_waitpipe[1]);
     for(;;) {
         rc = waitForInput(0, pty);
 
