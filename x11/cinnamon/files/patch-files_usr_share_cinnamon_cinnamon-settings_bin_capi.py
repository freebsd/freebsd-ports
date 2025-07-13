--- files/usr/share/cinnamon/cinnamon-settings/bin/capi.py.orig	2025-07-10 16:06:25 UTC
+++ files/usr/share/cinnamon/cinnamon-settings/bin/capi.py
@@ -30,7 +30,9 @@ class CManager:
         # get the arch-specific triplet, e.g. 'x86_64-linux-gnu' or 'arm-linux-gnueabihf'
         # see also: https://wiki.debian.org/Python/MultiArch
         triplet = sysconfig.get_config_var('MULTIARCH')
-        paths = ["/usr/lib", "/usr/lib64", f"/usr/lib/{triplet}"]
+        paths = ["/usr/lib", "/usr/lib64"]
+        if triplet:
+           paths.append(f"/usr/lib/{triplet}")
 
         # On x86 archs, iterate through multiple paths
         # For instance, on a Mint i686 box, the path is actually /usr/lib/i386-linux-gnu
