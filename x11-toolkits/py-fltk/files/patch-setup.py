--- setup.py.orig	2022-08-26 05:16:56 UTC
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
@@ -297,7 +297,7 @@ class PySwigCommand(distutils.cmd.Command):
 
   def run(self):
     """Run command."""
-    command = ['swig', '-w302', '-w312', '-w325', '-w362', '-w389', '-w401', '-w473', '-w509', '-I./swig', '-DFL_EXPORT', '-DPYTHON', '-DPYTHON3', '-py3', '-c++', '-python', '-shadow', '-fastdispatch', '-outdir', 'fltk', '-o', 'fltk/fltk_wrap.cpp', './swig/fltk.i']
+    command = ['swig', '-w302', '-w312', '-w325', '-w362', '-w389', '-w401', '-w473', '-w509', '-I./swig', '-DPYTHON', '-DPYTHON3', '-c++', '-python', '-shadow', '-fastdispatch', '-outdir', 'fltk', '-o', 'fltk/fltk_wrap.cpp', './swig/fltk.i']
     pos = command.index('-I./swig')+1
     command[pos:pos] = self.include
     self.announce(
