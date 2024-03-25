--- setup.py.orig	2023-03-01 22:36:20 UTC
+++ setup.py
@@ -175,7 +175,7 @@ class InstallData(install_data):
     return data_files
 
 
-if platform.system() in ['FreeBSD', 'OpenBSD']:
+if platform.system() in ['OpenBSD']:
   man_dir = 'man'
 else:
   man_dir = 'share/man'
