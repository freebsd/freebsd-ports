--- kdm/backend/client.c.orig	2010-03-26 18:26:49.000000000 +0100
+++ kdm/backend/client.c	2010-06-16 00:28:31.056683006 +0200
@@ -1271,6 +1271,9 @@
 	char ckDeviceBuf[20] = "";
 	const char *ckDevice = ckDeviceBuf;
 	dbus_bool_t isLocal;
+# ifdef BSD
+	FILE *proc;
+# endif
 #endif
 	char *failsafeArgv[2];
 	char *buf, *buf2;
@@ -1302,6 +1305,13 @@
 # ifdef HAVE_VTS
 	if (td->serverVT > 0)
 		sprintf( ckDeviceBuf, "/dev/tty%d", td->serverVT );
+# elif defined(BSD)
+	if ((proc = popen( "/usr/local/libexec/ck-get-x11-display-device", "r" ))) {
+		fscanf( proc, "%s", ckDeviceBuf );
+		pclose( proc );
+		if (strcmp( ckDeviceBuf, "usage" ) == 0 || strcmp( ckDeviceBuf, "ERROR:" ) == 0)
+			ckDeviceBuf[0] = '\0';
+	}
 # endif
 	isLocal = ((td->displayType & d_location) == dLocal);
 # ifdef XDMCP
