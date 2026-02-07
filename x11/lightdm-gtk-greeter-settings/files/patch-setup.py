--- setup.py.orig	2020-03-08 02:41:05 UTC
+++ setup.py
@@ -63,7 +63,7 @@ class InstallAndUpdateDataDirectory(DistUtilsExtra.aut
 
         values = {'__data_directory__': "'%s'" % (target_pkgdata),
                   '__version__': "'%s'" % self.distribution.get_version(),
-                  '__config_path__': '"/etc/lightdm/lightdm-gtk-greeter.conf"'}
+                  '__config_path__': '"%%LOCALBASE%%/etc/lightdm/lightdm-gtk-greeter.conf"'}
         write_config(self.install_lib, values)
 
         desktop_file_path = os.path.join(self.install_data, 'share', 'applications',
