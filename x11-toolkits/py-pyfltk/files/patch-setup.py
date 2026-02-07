--- setup.py.orig	2024-01-07 22:04:09 UTC
+++ setup.py
@@ -80,7 +80,7 @@ elif sys.platform.startswith('linux')  or sys.platform
     compile_arg_list.append('-Werror=format-security')
     lib_dir_list = [fltk_lib_dir, '/usr/lib']
     lib_list = ["fltk"]
-elif sys.platform in ['freebsd4','freebsd5','freebsd6','freebsd7', 'sunos5']:
+elif sys.platform[0:7] == 'freebsd':
     print(f"Building for: {sys.platform}")
     def_list = [('UNIX', '1')]
     lib_dir_list = [fltk_lib_dir,'/usr/X11R6/lib','/usr/lib']
