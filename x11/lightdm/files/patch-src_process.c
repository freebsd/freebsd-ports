--- src/process.c.orig	2018-08-30 00:28:55 UTC
+++ src/process.c
@@ -238,11 +238,16 @@ process_start (Process *process, gboolean block)
 
         /* Set environment */
         if (priv->clear_environment)
+        {
 #ifdef HAVE_CLEARENV
             clearenv ();
 #else
-            environ = NULL;
+            extern char **environ;
+            char *cleanenv[1];
+            environ = cleanenv;
+            cleanenv[0] = NULL;
 #endif
+        }
         for (guint i = 0; i < env_length; i++)
             setenv (env_keys[i], env_values[i], TRUE);
 
