--- src/settings.vala.orig	2019-08-21 08:46:54.280564000 -0300
+++ src/settings.vala	2019-08-21 08:47:45.224462000 -0300
@@ -107,7 +107,7 @@
     public static void apply_conf_settings ()
     {
         try {
-            var path = "/etc/lightdm/slick-greeter.conf";
+            var path = "/usr/local/etc/lightdm/slick-greeter.conf";
             var gsettings = new Settings (SCHEMA);
             var keyfile = new KeyFile ();

