--- main.c.orig	2015-08-27 11:22:17 UTC
+++ main.c
@@ -3679,7 +3679,7 @@ spawnXTerm(XtermWidget xw)
     added_utmp_entry = False;
 #if defined(USE_UTEMPTER)
 #undef UTMP
-    if (xw->misc.login_shell && !resource.utmpInhibit) {
+    if ((xw->misc.login_shell || !command_to_exec) && !resource.utmpInhibit) {
 	struct UTMP_STR dummy;
 
 	/* Note: utempter may trim it anyway */
