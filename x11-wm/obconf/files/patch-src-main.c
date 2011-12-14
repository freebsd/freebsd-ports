--- src/main.c.orig	2011-12-14 22:49:17.000000000 +0400
+++ src/main.c	2011-12-14 22:54:19.000000000 +0400
@@ -204,7 +204,7 @@
 
     if (obc_theme_archive) {
         archive_create(obc_theme_archive);
-        return;
+        return 0;
     }
 
     p = g_build_filename(GLADEDIR, "obconf.glade", NULL);
@@ -233,11 +233,10 @@
     }
 
     xmlIndentTreeOutput = 1;
-    if (!obt_xml_load_config_file(parse_i,
-                                  "openbox",
-                                  (obc_config_file ?
-                                   obc_config_file : "rc.xml"),
-                                  "openbox_config"))
+    if (!((obc_config_file &&
+           obt_xml_load_file(parse_i, obc_config_file, "openbox_config")) ||
+          obt_xml_load_config_file(parse_i, "openbox", "rc.xml",
+                                   "openbox_config")))
     {
         obconf_error(_("Failed to load an rc.xml. You have probably failed to install Openbox properly."), TRUE);
         exit_with_error = TRUE;
