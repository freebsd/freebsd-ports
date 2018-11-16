--- setup.py.orig	2016-12-29 09:36:33 UTC
+++ setup.py
@@ -106,7 +106,7 @@ elif sys.platform.startswith('linux'):
     compile_arg_list.append('-Werror=format-security')
     lib_dir_list = [fltk_lib_dir, '/usr/lib']
     lib_list = ["fltk"]
-elif sys.platform in ['freebsd4','freebsd5','freebsd6','freebsd7', 'sunos5']:
+elif sys.platform[0:7] == 'freebsd':
     print("Building for: %s"%sys.platform)
     def_list = [('UNIX', '1')]
     lib_dir_list = [fltk_lib_dir,'/usr/X11R6/lib','/usr/lib']
@@ -323,7 +323,6 @@ setup (name = 'pyFltk',
        description = 'This is a Python wrapper for the FLTK',
        ext_modules = [module1],
        packages = ['fltk'],
-       package_data={'fltk': ['test/*.*', 'docs/*.*']},
        )
 
 
