--- setup.py.orig	Tue Nov 11 21:53:44 2003
+++ setup.py	Tue Apr  6 19:31:33 2004
@@ -32,6 +32,11 @@
     lib_dir_list = [fltk_lib_dir]
     lib_list = ["fltk", "fltk_images", "fltk_forms",
 		    "fltk_gl", "GL", "jpeg", "png", "z"]
+elif sys.platform in ['freebsd4','freebsd5']:
+    def_list = [('UNIX', '1')]
+    lib_dir_list = [fltk_lib_dir,'/usr/X11R6/lib','/usr/local/lib']
+    lib_list = ["fltk", "fltk_images", "fltk_forms",
+		    "fltk_gl", "GL", "jpeg", "png", "z"]
 else:
     print "Platform not officially supported!"
     print "You can try to edit the platform specific settings in the file setup.py by creating an entry for the following platform: ", sys.platform
