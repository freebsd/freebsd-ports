
$FreeBSD$

--- help-converters/info/main.c	2002/02/20 18:02:08	1.1
+++ help-converters/info/main.c	2002/02/20 18:08:43
@@ -87,13 +87,15 @@
 	    char buf[PATH_MAX];
 
 	    /* First, find the directory that the info file is in. */
-	    dirs[0] = "/usr/info";
-	    dirs[1] = "/usr/share/info";
+	    dirs[0] = "/usr/share/info";
+	    dirs[1] = PREFIX "/info";
+	    dirs[2] = LOCALBASE "/info";
+	    dirs[3] = X11BASE "/info";
 	    /* We now have at least one directory to look in. This is
 	     * necessary because we may not have an 'INFOPATH' set */
-	    ndirs = 2;
+	    ndirs = 4;
 	    if(infopath)
-	      for(ndirs = 2, ctmp = strtok(infopath, ":"); ndirs < 64 && ctmp; ndirs++, ctmp = strtok(NULL, ":"))
+	      for(ndirs = 4, ctmp = strtok(infopath, ":"); ndirs < 64 && ctmp; ndirs++, ctmp = strtok(NULL, ":"))
 		dirs[ndirs] = strdup(ctmp);
 
 	    for(i = 0; i < ndirs; i++)
