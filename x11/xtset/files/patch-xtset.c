--- xtset.c.orig	2002-03-29 22:15:00.000000000 +1100
+++ xtset.c	2020-08-31 15:29:45.583899000 +1000
@@ -49,6 +49,7 @@
 #include <pwd.h>
 #include <grp.h>
 #include <sys/param.h>
+#include <sys/stat.h>
 
 /* SVR3 header files frequently don't define MAXPATHLEN. They probably can't
  * stomach a 1K path name, either, but this constant can err on the generous
@@ -135,21 +136,21 @@
 
   /* then the effective username */
 
-  if (pwent = getpwuid (geteuid ()))
+  if ((pwent = getpwuid (geteuid ())) != 0)
     eff_userid = strdup (pwent->pw_name);
   else
     eff_userid = "*no euid*";
 
   /* then the real groupname */
 
-  if (grent = getgrgid (getgid ()))
+  if ((grent = getgrgid (getgid ())) != 0)
     real_groupid = strdup (grent->gr_name);
   else
     real_groupid = "*no gid*";			    /* yes, this can be valid */
   
   /* then the effective groupname */
   
-  if (grent = getgrgid (getegid ()))
+  if ((grent = getgrgid (getegid ())) != 0)
     eff_groupid = strdup (grent->gr_name);
   else
     eff_groupid = "*no egid*";			    /* yes, this can be valid */
@@ -163,7 +164,7 @@
     {
     char *point;
     strcpy (short_host, our_host);
-    if (point = strchr (short_host, '.'))		    /* got a point, */
+    if ((point = strchr (short_host, '.')) != 0)	    /* got a point, */
       *point = '\0';					    /* chop it off there */
     }
   if ( !getcwd (our_dir, MAXPATHLEN))			    /* or can't get wd */
