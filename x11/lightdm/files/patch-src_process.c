--- src/process.c.orig	2017-01-26 22:04:26 UTC
+++ src/process.c
@@ -228,11 +228,16 @@ process_start (Process *process, gboolean block)
 
         /* Set environment */
         if (process->priv->clear_environment)
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
         for (i = 0; i < env_length; i++)
             setenv (env_keys[i], env_values[i], TRUE);
 
