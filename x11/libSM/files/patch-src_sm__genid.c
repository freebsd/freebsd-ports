--- src/sm_genid.c.orig	2018-10-10 15:05:03 UTC
+++ src/sm_genid.c
@@ -114,6 +114,8 @@ SmsGenerateClientID(SmsConn smsConn)
     size_t len;
 
     uuid_create(&uuid, &status);
+    if (status != uuid_s_ok)
+        return NULL;
 
     uuid_to_string(&uuid, &temp, &status);
 
