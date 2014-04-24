--- setup.py
+++ setup.py
@@ -12,6 +12,7 @@ from os import walk, environ
 from distutils.core import setup
 from distutils.extension import Extension
 from collections import OrderedDict
+from subprocess import check_output
 
 if sys.version > '3':
     PY3 = True
@@ -36,7 +37,6 @@ def pkgconfig(*packages, **kw):
         kw.setdefault(flag, []).append(token[2:].decode('utf-8'))
     return kw
 
-
 # -----------------------------------------------------------------------------
 # Determine on which platform we are
 
@@ -178,7 +178,7 @@ elif platform == 'win32':
     c_options['use_glew'] = True
 else:
     # searching GLES headers
-    default_header_dirs = ['/usr/include', '/usr/local/include']
+    default_header_dirs = ['/usr/include', join(environ.get('LOCALBASE', '/usr/local'), 'include')]
     found = False
     for hdir in default_header_dirs:
         filename = join(hdir, 'GLES2', 'gl2.h')
@@ -283,6 +283,9 @@ def determine_base_flags():
                        'ApplicationServices.framework/Frameworks')
         flags['extra_compile_args'] += ['-F%s' % sysroot]
         flags['extra_link_args'] += ['-F%s' % sysroot]
+    elif platform.startswith('freebsd'):
+        flags['include_dirs'] += [join(environ.get('LOCALBASE', '/usr/local'), 'include')]
+        flags['extra_link_args'] += ['-L', join(environ.get('LOCALBASE', '/usr/local'), 'lib')]
     return flags
 
 
@@ -297,8 +300,6 @@ def determine_gl_flags():
         flags['extra_link_args'] = ['-framework', 'OpenGL', '-arch', osx_arch]
         flags['extra_compile_args'] = ['-arch', osx_arch]
     elif platform.startswith('freebsd'):
-        flags['include_dirs'] = ['/usr/local/include']
-        flags['extra_link_args'] = ['-L', '/usr/local/lib']
         flags['libraries'] = ['GL']
     elif platform.startswith('openbsd'):
         flags['include_dirs'] = ['/usr/X11R6/include']
@@ -367,6 +368,11 @@ def determine_sdl():
     elif platform == 'darwin':
         flags['extra_link_args'] += [
             '-framework', 'ApplicationServices']
+    elif platform.startswith('freebsd'):
+        flags['extra_compile_args'] = check_output([environ.get('SDL2_CONFIG', 'sdl2-config'), '--cflags']).split()
+        flags['extra_link_args'] = check_output([environ.get('SDL2_CONFIG', 'sdl2-config'), '--libs']).split()
+        flags['include_dirs'] = []
+        flags['libraries'] = ["SDL2_ttf", "SDL2_mixer"]
     return flags
 
 
