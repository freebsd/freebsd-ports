--- src/process.c.orig	2016-12-08 21:38:14 UTC
+++ src/process.c
@@ -231,7 +231,7 @@ process_start (Process *process, gboolea
 #ifdef HAVE_CLEARENV
             clearenv ();
 #else
-            environ = NULL;
+            putenv ("environ=NULL");
 #endif
         for (i = 0; i < env_length; i++)
             setenv (env_keys[i], env_values[i], TRUE);
