--- kdm/backend/client.c.orig	2015-06-26 03:17:21 UTC
+++ kdm/backend/client.c
@@ -1322,6 +1322,9 @@ startClient(volatile int *pid)
     char ckDeviceBuf[20] = "";
     const char *ckDevice = ckDeviceBuf;
     dbus_bool_t isLocal;
+# ifdef BSD
+	FILE *proc;
+# endif
 #endif
     char *failsafeArgv[2];
     char *buf, *buf2;
@@ -1353,6 +1356,13 @@ startClient(volatile int *pid)
 # ifdef HAVE_VTS
     if (td->serverVT > 0)
         sprintf(ckDeviceBuf, "/dev/tty%d", td->serverVT);
+# elif defined(BSD)
+    if ((proc = popen( "/usr/local/libexec/ck-get-x11-display-device", "r" ))) {
+		fscanf( proc, "%s", ckDeviceBuf );
+		pclose(proc);
+		if (strcmp( ckDeviceBuf, "usage" ) == 0 || strcmp( ckDeviceBuf, "ERROR:" ) == 0)
+			ckDeviceBuf[0] = '\0';
+	}
 # endif
     isLocal = ((td->displayType & d_location) == dLocal);
 # ifdef XDMCP
@@ -1532,7 +1542,7 @@ startClient(volatile int *pid)
     environ = pam_env;
 # endif
     removeCreds = True; /* set it first - i don't trust PAM's rollback */
-    pretc = pam_setcred(pamh, 0);
+    pretc = pam_setcred(pamh, PAM_ESTABLISH_CRED);
     reInitErrorLog();
 # ifndef HAVE_PAM_GETENVLIST
     pam_env = environ;
