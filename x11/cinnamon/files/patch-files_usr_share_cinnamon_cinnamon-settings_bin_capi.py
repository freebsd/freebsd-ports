--- files/usr/share/cinnamon/cinnamon-settings/bin/capi.py.orig	2022-06-21 15:01:39 UTC
+++ files/usr/share/cinnamon/cinnamon-settings/bin/capi.py
@@ -27,31 +27,11 @@ class CManager():
         self.extension_point = Gio.io_extension_point_register ("cinnamon-control-center-1")
         self.modules = []
 
-        architecture = platform.machine()
-        # get the arch-specific triplet, e.g. 'x86_64-linux-gnu' or 'arm-linux-gnueabihf'
-        # see also: https://wiki.debian.org/Python/MultiArch
-        triplet = sysconfig.get_config_var('MULTIARCH')
-        paths = ["/usr/lib", f"/usr/lib/{triplet}"]
-
-        # On x86 archs, iterate through multiple paths
-        # For instance, on a Mint i686 box, the path is actually /usr/lib/i386-linux-gnu
-        x86archs = ["i386", "i486", "i586", "i686"]
-        if architecture in x86archs:
-            for arch in x86archs:
-                paths += ["/usr/lib/%s" % arch]
-        elif architecture == "x86_64":
-            paths += ["/usr/lib/x86_64", "/usr/lib64"]
-        else:
-            paths += ["/usr/lib/%s" % architecture]
-
-        for path in paths:
-            if not os.path.islink(path):
-                path = os.path.join(path, "cinnamon-control-center-1/panels")
-                if os.path.exists(path):
-                    try:
-                        self.modules = self.modules + Gio.io_modules_load_all_in_directory(path)
-                    except Exception as e:
-                        print("capi failed to load multiarch modules from %s: " % path, e)
+        path = os.path.join("/usr/lib", "cinnamon-control-center-1/panels")
+        try:
+            self.modules = self.modules + Gio.io_modules_load_all_in_directory(path)
+        except Exception as e:
+            print("capi failed to load multiarch modules from %s: " % path, e)
 
     def get_c_widget(self, mod_id):
         extension = self.extension_point.get_extension_by_name(mod_id)
