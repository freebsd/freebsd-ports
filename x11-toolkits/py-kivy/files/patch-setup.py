--- setup.py.orig	2013-05-28 15:08:56.000000000 +0200
+++ setup.py	2013-11-18 20:41:50.000000000 +0200
@@ -6,9 +6,10 @@
 import sys
 from copy import deepcopy
 from os.path import join, dirname, sep, exists
-from os import walk, environ
+from os import walk, environ, path
 from distutils.core import setup
 from distutils.extension import Extension
+from subprocess import check_output
 
 # -----------------------------------------------------------------------------
 # Determine on which platform we are
@@ -124,7 +125,7 @@
     c_options['use_glew'] = True
 else:
     # searching GLES headers
-    default_header_dirs = ['/usr/include', '/usr/local/include']
+    default_header_dirs = ['/usr/include', path.join(environ.get('LOCALBASE', '/usr/local'), 'include')]
     found = False
     for hdir in default_header_dirs:
         filename = join(hdir, 'GLES2', 'gl2.h')
@@ -201,6 +202,9 @@
         sysroot = '/System/Library/Frameworks/ApplicationServices.framework/Frameworks'
         flags['extra_compile_args'] += ['-F%s' % sysroot]
         flags['extra_link_args'] += ['-F%s' % sysroot]
+    elif platform.startswith('freebsd'):
+        flags['include_dirs'] += [path.join(environ.get('LOCALBASE', '/usr/local'), 'include')]
+        flags['extra_link_args'] += ['-L', path.join(environ.get('LOCALBASE', '/usr/local'), 'lib')]
     return flags
 
 def determine_gl_flags():
@@ -214,8 +218,6 @@
         flags['extra_link_args'] = ['-framework', 'OpenGL', '-arch', 'x86_64']
         flags['extra_compile_args'] = ['-arch', 'x86_64']
     elif platform.startswith('freebsd'):
-        flags['include_dirs'] = ['/usr/local/include']
-        flags['extra_link_args'] = ['-L', '/usr/local/lib']
         flags['libraries'] = ['GL']
     elif platform.startswith('openbsd'):
         flags['include_dirs'] = ['/usr/X11R6/include']
@@ -283,6 +285,11 @@
     elif platform == 'darwin':
         flags['extra_link_args'] += [
             '-framework', 'ApplicationServices']
+    elif platform.startswith('freebsd'):
+        flags['extra_compile_args'] = check_output([environ.get('SDL2_CONFIG', 'sdl2-config'), '--cflags']).split()
+        flags['extra_link_args'] = check_output([environ.get('SDL2_CONFIG', 'sdl2-config'), '--libs']).split()
+        flags['include_dirs'] = []
+        flags['libraries'] = ["SDL2_ttf", "SDL2_mixer"]
     return flags
 
 def determine_graphics_pxd():
@@ -491,13 +498,7 @@
         'data/glsl/*.fs',
         'tools/highlight/*.vim',
         'tools/highlight/*.el',
-        'tools/packaging/README.txt',
-        'tools/packaging/win32/kivy.bat',
-        'tools/packaging/win32/kivyenv.sh',
-        'tools/packaging/win32/README.txt',
-        'tools/packaging/osx/Info.plist',
-        'tools/packaging/osx/InfoPlist.strings',
-        'tools/packaging/osx/kivy.sh']},
+        'tools/packaging/README.txt']},
     data_files=examples.items(),
     classifiers=[
         'Development Status :: 5 - Production/Stable',
