
$FreeBSD$

--- my_distutils.py	2001/05/28 14:50:41	1.1
+++ my_distutils.py	2001/05/28 14:51:09
@@ -122,10 +122,10 @@
 
 from distutils import ccompiler
 
-ccompiler.default_compiler['nt'] = 'my_msvc'
-ccompiler.compiler_class['my_msvc'] = ('my_distutils',
-                                       'MyMSVCCompiler',
-                                       'My MSVC derived class')
+#ccompiler.default_compiler['nt'] = 'my_msvc'
+#ccompiler.compiler_class['my_msvc'] = ('my_distutils',
+#                                       'MyMSVCCompiler',
+#                                       'My MSVC derived class')
 
 
 # make it look like it is part of the package...
