--- libgnome/gnome-program.c.orig	Fri Jan 14 01:38:31 2005
+++ libgnome/gnome-program.c	Fri Jan 14 01:39:01 2005
@@ -1928,6 +1928,8 @@
                            int argc, char **argv,
                            guint nparams, GParameter *params)
 {
+    va_list args;
+
     return gnome_program_init_common (type, app_id, app_version, module_info,
-				      argc, argv, NULL, 0, nparams, params);
+				      argc, argv, NULL, args, nparams, params);
 }
