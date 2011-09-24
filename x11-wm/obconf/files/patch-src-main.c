--- src/main.c.orig
+++ src/main.c
@@ -233,11 +233,10 @@ int main(int argc, char **argv)
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
