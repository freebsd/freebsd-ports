--- kdesu/kdesu_stub.c.orig	Wed Nov 22 10:10:17 2000
+++ kdesu/kdesu_stub.c	Wed Nov 22 10:31:12 2000
@@ -276,9 +276,17 @@
 	xsetenv("DISPLAY", params[P_DISPLAY].value);
 	if (params[P_DISPLAY_AUTH].value[0]) 
 	{
+#ifdef HAVE_MKSTEMP
+            int fd;
+            strcpy(fname, "/tmp/kdesu.XXXXXXXX");
+	    fout = fdopen(fd, "w");
+	    fd = mkstemp(fname);
+	    if (fd == -1 || fout == NULL)
+#else
 	    fname = tmpnam(0L);
 	    fout = fopen(fname, "w");
 	    if (!fout) 
+#endif
 	    {
 		perror("kdesu_stub: fopen()");
 		exit(1);
@@ -286,7 +294,22 @@
 	    fprintf(fout, "add %s %s\n", params[P_DISPLAY].value,
 		    params[P_DISPLAY_AUTH].value);
 	    fclose(fout);
+#ifdef HAVE_MKSTEMP
+	    strcpy(xauthority, "/tmp/xauth.XXXXXXXX");
+	    {
+		int fd;
+		fd = mkstemp(xauthority);
+		if (fd == -1)
+		{
+		    perror("kdesu_stub: mkstemp()");
+		    exit(1);
+                }
+		else
+		    close(fd);
+            }
+#else
 	    tmpnam(xauthority);
+#endif
 	    xsetenv("XAUTHORITY", xauthority);
 	    sprintf(command, "xauth source %s >/dev/null 2>&1", fname);
 	    if (system(command))
@@ -305,9 +328,17 @@
 	auth = xstrsep(params[P_ICE_AUTH].value);
 	if (host[0]) 
 	{
+#ifdef HAVE_MKSTEMP
+	    int fd;
+	    strcpy(fname, "/tmp/kdesu.XXXXXXXX");
+	    fd = mkstemp(fname);
+	    fout = fdopen(fd, "w");
+	    if (fd == -1 || fout == NULL)
+#else
 	    fname = tmpnam(0L);
 	    fout = fopen(fname, "w");
 	    if (!fout) 
+#endif
 	    {
 		perror("kdesu_stub: fopen()");
 		exit(1);
@@ -318,7 +349,22 @@
 	    for (i=0; host[i]; i++)
 		fprintf(fout, "add DCOP \"\" %s %s\n", host[i], auth[i]);
 	    fclose(fout);
+#ifdef HAVE_MKSTEMP
+	    strcpy(iceauthority, "/tmp/iceauth.XXXXXXXX");
+	    {
+		int fd; 
+		fd = mkstemp(iceauthority);
+		if (fd == -1)
+		{
+		    perror("kdesu_stub: mkstemp()");
+		    exit(1);
+                }
+		else
+		    close(fd);
+            }
+#else
 	    tmpnam(iceauthority);
+#endif
 	    xsetenv("ICEAUTHORITY", iceauthority);
 	    sprintf(command, "iceauth source %s >/dev/null 2>&1", fname);
 	    if (system(command))
