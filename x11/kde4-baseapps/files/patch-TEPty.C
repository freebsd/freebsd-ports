--- konsole/src/TEPty.C.orig	Fri Dec  8 11:51:24 2000
+++ konsole/src/TEPty.C	Fri Dec  8 11:52:51 2000
@@ -180,27 +180,57 @@
 // param grant: 1 to grant, 0 to revoke
 // returns 1 on success 0 on fail
 {
-  pid_t pid = fork();
-  if (pid < 0)
-  {
-    return 0;
-  }
-  if (pid == 0)
-  {
-    /* We pass the master pseudo terminal as file descriptor PTY_FILENO. */
-    if (fd != PTY_FILENO && dup2(fd, PTY_FILENO) < 0) exit(1);
-    QString path = locate("exe", BASE_CHOWN);
+  pid_t pid;
+  int pstat;
+  struct sigaction ign;
+  struct sigaction intact;	// interupt action
+  struct sigaction quitact;	// quit action
+  sigset_t newsigblock, oldsigblock;
+	QString path;
+
+  ign.sa_handler = SIG_IGN;
+  sigemptyset(&ign.sa_mask);
+  ign.sa_flags = 0;
+  sigaction(SIGINT, &ign, &intact);
+  sigaction(SIGQUIT, &ign, &quitact);
+  sigemptyset(&newsigblock);
+  sigaddset(&newsigblock, SIGCHLD);
+  sigprocmask(SIG_BLOCK, &newsigblock, &oldsigblock);
+
+  switch (pid = fork()) {
+  case -1:
+    return(0);
+		break;
+  case 0:			// child
+    if (fd != PTY_FILENO && dup2(fd, PTY_FILENO) < 0)
+      exit(1);
+    path = locate("exe", BASE_CHOWN);
+
+    sigaction(SIGINT, &intact, NULL);
+    sigaction(SIGQUIT, &quitact, NULL);
+    sigprocmask(SIG_SETMASK, &oldsigblock, NULL);
     execle(path.ascii(), BASE_CHOWN, grant?"--grant":"--revoke", NULL, NULL);
-    exit(1); // should not be reached
-  }
-  if (pid > 0)
-  { int w;
-  retry:
-    int rc = waitpid (pid, &w, 0);
-    if ((rc == -1) && (errno == EINTR))
-      goto retry;
-    return (rc != -1 && WIFEXITED(w) && WEXITSTATUS(w) == 0);
+    exit(1);
+		break;
+  default:
+    do {
+      pid = waitpid(pid, &pstat, 0);
+    } while (pid == -1 && errno == EINTR);
+    break;
   }
+  sigaction(SIGINT, &intact, NULL);
+  sigaction(SIGQUIT, &quitact, NULL);
+  sigprocmask(SIG_SETMASK, &oldsigblock, NULL);
+
+  if (pid == -1) {
+    return 0;
+	}
+  else if (WIFEXITED(pstat) && (WEXITSTATUS(pstat) == 0)) {
+    return 1;
+	}
+  else {
+    return 0;
+	}
   return 0; //dummy.
 }
 
@@ -225,7 +255,7 @@
 #ifdef HAVE_UTEMPTER
   removeLineFromUtmp(ttynam, fd);
 #elif defined(USE_LOGIN)
-  char *tty_name=ttyname(0);
+  char *tty_name=ttyname(fd);
   if (tty_name)
   {
   	if (strncmp(tty_name, "/dev/", 5) == 0)
