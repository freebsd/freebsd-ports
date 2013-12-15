--- setup.py.orig	2008-03-23 16:15:12.000000000 -0300
+++ setup.py	2013-12-13 11:36:29.526423229 -0200
@@ -104,7 +104,6 @@
             if self.root is None:
                 print "Running gtk-update-icon-cache"
                 subprocess.call(['gtk-update-icon-cache', os.path.join(self.install_data, 'icons')])
-kwargs['cmdclass']['install'] = HotInstall                    
 
 setup(name='hotwire',
       version=__version__,
