--- src/bin/e_main.c.orig
+++ src/bin/e_main.c
@@ -462,15 +462,6 @@ main(int argc, char **argv)
    TS("E_Alert Init Done");
    _e_main_shutdown_push(e_alert_shutdown);

-   TS("E_Xinerama Init");
-   if (!e_xinerama_init())
-     {
-        e_error_message_show(_("Enlightenment cannot initialize E_Xinerama!\n"));
-        _e_main_shutdown(-1);
-     }
-   TS("E_Xinerama Init Done");
-   _e_main_shutdown_push(e_xinerama_shutdown);
-
    TS("E_Hints Init");
    e_hints_init();
    TS("E_Hints Init Done");
@@ -521,6 +512,15 @@ main(int argc, char **argv)
      _e_main_shutdown_push(e_randr_shutdown);
    TS("E_Randr Init Done");

+   TS("E_Xinerama Init");
+   if (!e_xinerama_init())
+     {
+        e_error_message_show(_("Enlightenment cannot initialize E_Xinerama!\n"));
+        _e_main_shutdown(-1);
+     }
+   TS("E_Xinerama Init Done");
+   _e_main_shutdown_push(e_xinerama_shutdown);
+
    TS("E_Env Init");
    if (!e_env_init())
      {
