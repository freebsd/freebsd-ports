--- files/usr/lib/cinnamon-settings/cinnamon-settings.orig.py	2013-02-26 17:20:22.252933982 +0100
+++ files/usr/lib/cinnamon-settings/cinnamon-settings.py	2013-02-26 17:21:19.081928251 +0100
@@ -17,7 +17,8 @@
     if len(mod_files) is 0:
         raise Exception("No settings modules found!!")
     for i in range(len(mod_files)):
-        mod_files[i] = mod_files[i].split('/')[5]
+        mod_files[i] = mod_files[i].split('/')
+        mod_files[i] = mod_files[i][len(mod_files[i])-1]
         mod_files[i] = mod_files[i].split('.')[0]
         if mod_files[i][0:3] != "cs_":
             raise Exception("Settings modules must have a prefix of 'cs_' !!")
