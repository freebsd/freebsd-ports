'system-hibernate' and 'system-suspend' icons don't exist when Gnome or
Adwaita are default icons theme.

--- plugins/actions/actions.c.orig	2013-05-05 15:47:07 UTC
+++ plugins/actions/actions.c
@@ -181,7 +181,7 @@ static ActionEntry action_entries[] =
     N_("_Hibernate"),
     N_("Do you want to suspend to disk?"),
     N_("Hibernating computer in %d seconds."),
-    "system-hibernate"
+    "xfsm-hibernate"
   },
   { ACTION_TYPE_SUSPEND,
     "suspend",
@@ -189,7 +189,7 @@ static ActionEntry action_entries[] =
     N_("Sus_pend"),
     N_("Do you want to suspend to RAM?"),
     N_("Suspending computer in %d seconds."),
-    "system-suspend"
+    "xfsm-suspend"
   },
   { ACTION_TYPE_RESTART,
     "restart",
