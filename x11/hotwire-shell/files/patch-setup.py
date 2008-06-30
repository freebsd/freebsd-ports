
$FreeBSD$

--- setup.py.orig
+++ setup.py
@@ -103,7 +103,7 @@
         if os.name == 'posix':                       
             if self.root is None:
                 print "Running gtk-update-icon-cache"
-                subprocess.call(['gtk-update-icon-cache', os.path.join(self.install_data, 'icons')])
+                subprocess.call(['gtk-update-icon-cache', os.path.join(self.install_data, 'share', 'icons', 'hicolor')])
 kwargs['cmdclass']['install'] = HotInstall                    
 
 setup(name='hotwire',
