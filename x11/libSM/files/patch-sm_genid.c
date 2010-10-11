--- src/sm_genid.c.orig	2009-08-07 02:38:31.000000000 -0700
+++ src/sm_genid.c	2010-10-11 15:00:42.000000000 -0700
@@ -88,17 +88,21 @@
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
+    if (status != uuid_s_ok)
+        return NULL;
 
     if ((id = malloc (strlen (temp) + 2)) != NULL)
     {
-        id[1] = '2';
+        id[0] = '2';
         strcpy (id+1, temp);
     }
 
