--- src/sm_genid.c.orig	2008-06-24 21:11:27.000000000 +0400
+++ src/sm_genid.c	2009-02-23 18:51:22.000000000 +0300
@@ -76,7 +76,9 @@
 #define TCPCONN
 #endif
 
-#if defined(HAVE_LIBUUID)
+#if defined(HAVE_STDUUID)
+#include <uuid.h>
+#elif defined(HAVE_LIBUUID)
 #include <uuid/uuid.h>
 #endif
 
@@ -85,7 +87,28 @@
 SmsGenerateClientID (smsConn)
     SmsConn smsConn;
 {
-#if defined(HAVE_LIBUUID)
+#if defined(HAVE_STDUUID)
+    char *id;
+    char *str;
+    uuid_t uuid;
+    uint32_t status;
+
+    uuid_create(&uuid, &status);
+    if (status != uuid_s_ok)
+	return NULL;
+
+    uuid_to_string(&uuid, &str, &status);
+    if (status != uuid_s_ok)
+	return NULL;
+
+    if ((id = malloc (strlen (str) + 2)) != NULL) {
+	id[0] = '2';
+	strcpy(&id[1], str);
+    }
+    free(str);
+
+    return id;
+#elif defined(HAVE_LIBUUID)
     char *id;
     char temp[256];
     uuid_t uuid;
