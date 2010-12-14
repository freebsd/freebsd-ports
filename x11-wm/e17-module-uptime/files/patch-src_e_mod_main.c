--- src/e_mod_main.c.orig	2010-12-13 22:26:02.000000000 -0800
+++ src/e_mod_main.c	2010-12-13 22:31:44.000000000 -0800
@@ -4,7 +4,17 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <sys/types.h>
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#if __FreeBSD_version >= 900007
+#define	USE_UTMPX
+#endif
+#endif
+#if defined(USE_UTMPX)
+#include <utmpx.h>
+#else
 #include <utmp.h>
+#endif
 
 #if TIME_WITH_SYS_TIME
 # include <sys/time.h>
@@ -434,12 +444,16 @@
    struct timeval boottime;
    time_t now;
 
+#if defined(USE_UTMPX)
+   struct utmpx *utmpstruct;
+#else
    FILE *utmp;
    struct timespec tp;
    struct utmp ut;
    char ttybuf[MAXPATHLEN];
    struct stat st;
 #endif
+#endif
 
    if (!inst) return;
 
@@ -487,6 +501,17 @@
 # endif
 
   /* retrive number of active users */
+#if defined(USE_UTMPX)
+   inst->nusers = 0;
+   setutxent ();
+   while ((utmpstruct = getutxent ()))
+     {
+        if ((utmpstruct->ut_type == USER_PROCESS) &&
+           (utmpstruct->ut_user[0] != '\0'))
+              inst->nusers++;
+     }
+   endutxent ();
+#else
    utmp = fopen (_PATH_UTMP, "r");
    if (!utmp)
      inst->nusers = -1;
@@ -504,6 +529,7 @@
 	}
 	fclose (utmp);
     }
+#endif
 #else /* unsupported */
    inst->uptime = -1;
    inst->nusers = -1;
