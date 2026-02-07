--- lxsession-default-apps/main.vala.orig	2016-12-10 10:31:17 UTC
+++ lxsession-default-apps/main.vala
@@ -125,7 +125,7 @@ namespace LDefaultApps
                 else
                 {
                     /* TODO Make it smart with prefix */
-                    builder_file_path = Path.build_filename("/usr","share","lxsession","ui","lxsession-default-apps.ui");
+                    builder_file_path = Path.build_filename("%%PREFIX%%","share","lxsession","ui","lxsession-default-apps.ui");
                     builder.add_from_file (builder_file_path);
                 }
             } 
