--- src/sm_genid.c.orig	2010-06-04 20:15:04.000000000 +0200
+++ src/sm_genid.c	2011-08-06 20:15:47.000000000 +0200
@@ -111,11 +111,13 @@ SmsGenerateClientID(SmsConn smsConn)
 {
 #if defined(HAVE_UUID_CREATE)
     char *id;
-    char **temp;
+    char *temp;
     uuid_t uuid;
     uint32_t status;
 
     uuid_create(&uuid, &status);
+    if (status != uuid_s_ok)
+        return NULL;
 
     uuid_to_string(&uuid, &temp, &status);
 
