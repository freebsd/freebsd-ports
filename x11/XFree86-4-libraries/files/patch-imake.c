--- config/imake/imake.c.orig	Tue Dec 17 04:21:38 2002
+++ config/imake/imake.c	Sat Jan  4 15:57:23 2003
@@ -1384,6 +1384,19 @@
 	  name = &uts_name;
       }
 #endif
+# ifdef __FreeBSD__
+       /* Hack for FreeBSD ports "Cross Version" compiling system. */
+       {
+	 char *e;
+	 if ((e = getenv("OSREL")) != NULL && 
+	     strlen(name->sysname) + strlen(e) + 1 < SYS_NMLN) {
+	  strcpy(name->release, e);
+	  strcpy(name->version, name->sysname);
+	  strcat(name->version, " ");
+	  strcat(name->version, e);
+	 }
+       }
+# endif
 
 #  if defined DEFAULT_OS_NAME
 #   if defined CROSSCOMPILE
