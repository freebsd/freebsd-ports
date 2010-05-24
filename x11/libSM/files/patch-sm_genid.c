--- src/sm_genid.c.orig	2010-05-24 14:21:20.000000000 -0400
+++ src/sm_genid.c	2010-05-24 14:21:44.000000000 -0400
@@ -98,7 +98,7 @@
 
     if ((id = malloc (strlen (temp) + 2)) != NULL)
     {
-        id[1] = '2';
+        id[0] = '2';
         strcpy (id+1, temp);
     }
 
