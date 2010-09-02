--- ./kdm/backend/client.c.orig	2010-07-06 10:54:30.000000000 +0400
+++ ./kdm/backend/client.c	2010-07-30 22:23:48.264408318 +0400
@@ -1309,6 +1309,9 @@
     char ckDeviceBuf[20] = "";
     const char *ckDevice = ckDeviceBuf;
     dbus_bool_t isLocal;
+# ifdef BSD
+	FILE *proc;
+# endif
 #endif
     char *failsafeArgv[2];
     char *buf, *buf2;
@@ -1340,6 +1343,13 @@
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
