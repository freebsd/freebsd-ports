--- konsole/konsole/TEPty.cpp	22 Nov 2002 13:17:57 -0000	1.75
+++ konsole/konsole/TEPty.cpp	24 Aug 2003 21:44:00 -0000
@@ -65,6 +65,9 @@
 #include <config.h>
 #endif

+// Get the Q_OS_* defines
+#include <qglobal.h>
+
 #ifdef __sgi
 #define __svr4__
 #endif
@@ -88,6 +91,10 @@
 #include <sys/types.h>
 #endif

+#ifdef Q_OS_FREEBSD
+#include <sys/param.h>
+#endif
+
 #include <stdlib.h>
 #include <stdio.h>
 
@@ -198,9 +205,30 @@ public:
 
 FILE* syslog_file = NULL; //stdout;

-#define PTY_FILENO 3
+#define DEFAULT_PTY_FILENO 3
+int PTY_FILENO = -1; // None allocated yet.
+
 #define BASE_CHOWN "konsole_grantpty"

+void TEPtyInit()
+{
+/*
+** FreeBSD can't dup2(fd,3) because fd 3 is already in use by
+** some weird pipe. So instead, we get a new throwaway fd
+** that's not in use by anyone.
+*/
+#ifdef Q_OS_FREEBSD
+  PTY_FILENO = open("/dev/null",O_RDWR);
+  if (PTY_FILENO == -1) {
+    perror("konsole:open PTY");
+    /* This won't work either, but hey .. */
+    PTY_FILENO = DEFAULT_PTY_FILENO;
+  }
+#else
+  PTY_FILENO = DEFAULT_PTY_FILENO;
+#endif
+}
+
 int chownpty(int fd, bool grant)
 // param fd: the fd of a master pty.
 // param grant: true to grant, false to revoke
@@ -212,6 +240,8 @@ int chownpty(int fd, bool grant)
   newsa.sa_flags = 0;
   sigaction(SIGCHLD, &newsa, &oldsa);

+  if (PTY_FILENO == -1) TEPtyInit();
+
   pid_t pid = fork();
   if (pid < 0)
   {
@@ -225,7 +255,12 @@ int chownpty(int fd, bool grant)
     /* We pass the master pseudo terminal as file descriptor PTY_FILENO. */
     if (fd != PTY_FILENO && dup2(fd, PTY_FILENO) < 0) exit(1);
     QString path = locate("exe", BASE_CHOWN);
-    execle(path.ascii(), BASE_CHOWN, grant?"--grant":"--revoke", NULL, NULL);
+    /*
+    ** Because konsole_grantpty now can't expect the fd
+    ** to be constant, we need an additional parameter.
+    */
+    QString fdnumber = QString::number(PTY_FILENO);
+    execle(path.ascii(), BASE_CHOWN, grant?"--grant":"--revoke", fdnumber.ascii(), NULL, NULL);
     exit(1); // should not be reached
   }
 
@@ -486,6 +521,16 @@ int TEPty::makePty(bool _addutmp)
   // open and set all standard files to slave tty
   int tt = m_SlaveFd; // Already opened?
 
+#ifdef Q_OS_FREEBSD
+  /*
+  ** It seems to be possible for SlaveFd to be closed in error
+  ** somewhere along the line. So check it for "liveness".
+  */
+  struct stat sb;
+  if (fstat(tt,&sb)!=0)
+    tt=-1; // Apparently not alive.
+#endif
+
   if (tt < 0)
     tt = open(ttynam, O_RDWR);

@@ -524,14 +569,57 @@ int TEPty::makePty(bool _addutmp)
   }
   strncpy(l_struct.ut_name, str_ptr, UT_NAMESIZE);

+#ifdef Q_OS_FREEBSD
+     /* FreeBSD until august 22, 2003 returned ENOMEM for too-long
+     ** hostnames. Then sanity prevailed (?) and the error was changed
+     ** to NAMETOOLONG, but this breaks konsole .. again.
+     **
+     ** Instead of bailing out with long hostnames, put in partial
+     ** hostnames (the first UT_HOSTSIZE characters) instead.
+     */
+  char hostnamebuffer[MAXHOSTNAMELEN+1];
+  memset(hostnamebuffer,0,MAXHOSTNAMELEN+1);
+  if (gethostname(hostnamebuffer, MAXHOSTNAMELEN) == -1)
+  {
+     if ( (errno==ENOMEM) || (errno==ENAMETOOLONG) ) {
+       /* ignore it, but very odd */
+     }
+     else {
+       /* Not much chance of this being visible anywhere ... */
+       perror("konsole:gethostname");
+       abort();
+     }
+  }
+  /* Copy hostname, possibly only partially */
+  memset(l_struct.ut_host,0,UT_HOSTSIZE);
+  strncpy(l_struct.ut_host,hostnamebuffer,UT_HOSTSIZE);
+  l_struct.ut_host[UT_HOSTSIZE]=0;
+#else
+  /* Non-FreeBSD systems */
   if (gethostname(l_struct.ut_host, UT_HOSTSIZE) == -1) {
-     if (errno != ENOMEM)
+     if  (errno != ENOMEM)
         abort();
      l_struct.ut_host[UT_HOSTSIZE]=0;
   }
+#endif

   if (! (str_ptr=ttyname(tt)) ) {
+#ifdef Q_OS_FREEBSD
+    /*
+    ** In FreeBSD, the ttyname() call always returns NULL
+    ** for the kinds of devices (ptys) we have opened,
+    ** so don't abort, use a foolish default value instead.
+    ** The call to login() probably won't work _anyway_,
+    ** since normally users can't update the wtmp file.
+    **
+    ** If we were real sticklers for accuracy, we'd copy the
+    ** code from konsole_grantpty that does it's darndest to
+    ** file out the right tty name.
+    */
+    str_ptr = const_cast<char *>("/dev/konsole");
+#else
     abort();
+#endif
   }
   if (strncmp(str_ptr, "/dev/", 5) == 0)
        str_ptr += 5;
@@ -607,7 +695,7 @@ void TEPty::startPgm(const char* pgm, QV
 // #define CERASE 0177
 // #endif

-#if defined (__FreeBSD__) || defined (__NetBSD__) || defined (__OpenBSD__) || defined (__bsdi__) || defined(__APPLE__)
+#if defined (Q_OS_FREEBSD) || defined (__NetBSD__) || defined (__OpenBSD__) || defined (__bsdi__) || defined(__APPLE__)
       ioctl(0,TIOCGETA,(char *)&ttmode);
 #else
 #   if defined (_HPUX_SOURCE) || defined(__Lynx__)
@@ -621,7 +709,7 @@ void TEPty::startPgm(const char* pgm, QV
       ttmode.c_cc[VINTR] = CTRL('C');
       ttmode.c_cc[VQUIT] = CTRL('\\');
       ttmode.c_cc[VERASE] = 0177;
-#if defined (__FreeBSD__) || defined (__NetBSD__) || defined (__OpenBSD__) || defined (__bsdi__) || defined(__APPLE__)
+#if defined (Q_OS_FREEBSD) || defined (__NetBSD__) || defined (__OpenBSD__) || defined (__bsdi__) || defined(__APPLE__)
       ioctl(0,TIOCSETA,(char *)&ttmode);
 #else
 #   ifdef _HPUX_SOURCE