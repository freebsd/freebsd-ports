--- src/actions.c.orig	Wed Oct  5 03:25:29 2005
+++ src/actions.c	Wed Oct  5 03:26:02 2005
@@ -120,8 +120,8 @@
  * Pin the current window to all workspaces.
  */
 ESExpResult *func_pin(ESExp *f, int argc, ESExpResult **argv, Context *c) {
-  wnck_window_stick (c->window);
-  if (debug) g_printerr(_("Setting sticky\n"));
+  wnck_window_pin (c->window);
+  if (debug) g_printerr(_("Setting pinned\n"));
   return e_sexp_result_new_bool (f, TRUE);
 }
 
@@ -129,8 +129,8 @@
  * Unpin the current window from all workspaces.
  */
 ESExpResult *func_unpin(ESExp *f, int argc, ESExpResult **argv, Context *c) {
-  wnck_window_unstick (c->window);
-  if (debug) g_printerr(_("Unsetting sticky\n"));
+  wnck_window_unpin (c->window);
+  if (debug) g_printerr(_("Unsetting pinned\n"));
   return e_sexp_result_new_bool (f, TRUE);
 }
 
