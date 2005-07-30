--- setup.py.orig	Tue Nov  9 20:59:17 2004
+++ setup.py	Sat Jul 30 21:19:17 2005
@@ -44,7 +44,7 @@
     lib_dir_list = [fltk_lib_dir]
     lib_list = ["fltk", "fltk_images", "fltk_forms",
 		    "fltk_gl", "GL", "jpeg", "png", "z"]
-elif sys.platform in ['freebsd4','freebsd5']:
+elif sys.platform in ['freebsd4','freebsd5','freebsd6','freebsd7']:
     print "Building for FreeBSD"
     def_list = [('UNIX', '1')]
     lib_dir_list = [fltk_lib_dir,'/usr/X11R6/lib','/usr/local/lib']
