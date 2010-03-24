--- e_mod_main.c
+++ e_mod_main.c
@@ -4,7 +4,7 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <sys/types.h>
-#include <utmp.h>
+#include <utmpx.h>
 
 #if TIME_WITH_SYS_TIME
 # include <sys/time.h>
@@ -445,11 +445,7 @@
   struct timeval boottime;
   time_t now;
 
-  FILE *utmp;
-  struct timespec tp;
-  struct utmp ut;
-  char ttybuf[MAXPATHLEN];
-  struct stat st;
+  struct utmpx *utmpstruct;
 #endif
 
   if (!inst)
@@ -498,26 +494,15 @@
   if (ret < 0)
     warn ("getloadavg()");
 # endif
-
-  /* retrive number of active users */
-  utmp = fopen (_PATH_UTMP, "r");
-  if (utmp == NULL)
-    inst->nusers = -1;
-  else
+  inst->nusers = 0;
+  setutxent ();
+  while ((utmpstruct = getutxent ()))
     {
-      for (inst->nusers = 0; fread (&ut, sizeof (ut), 1, utmp);)
-	{
-	  if (ut.ut_name[0] == '\0')
-	    continue;
-	  (void) snprintf (ttybuf, sizeof (ttybuf), "%s%.*s", _PATH_DEV,
-			   UT_LINESIZE, ut.ut_line);
-	  if (stat (ttybuf, &st) != 0)
-	    continue;		/* broken record */
-
-	  inst->nusers++;
-	}
-      fclose (utmp);
+      if ((utmpstruct->ut_type == USER_PROCESS) &&
+	  (utmpstruct->ut_user[0] != '\0'))
+	inst->nusers++;
     }
+  endutxent ();
 #else /* unsupported */
   inst->uptime = -1;
   inst->nusers = -1;
