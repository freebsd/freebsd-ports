--- pyscreeze/__init__.py.orig	2025-07-05 20:35:11 UTC
+++ pyscreeze/__init__.py
@@ -64,7 +64,7 @@ try:
 
 GNOMESCREENSHOT_EXISTS = False
 try:
-    if sys.platform.startswith('linux'):
+    if sys.platform.startswith('linux') or sys.platform.startswith('freebsd'):
         whichProc = subprocess.Popen(['which', 'gnome-screenshot'], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
         GNOMESCREENSHOT_EXISTS = whichProc.wait() == 0
 except OSError as ex:
@@ -77,7 +77,7 @@ try:
 
 SCROT_EXISTS = False
 try:
-    if sys.platform.startswith('linux'):
+    if sys.platform.startswith('linux') or sys.platform.startswith('freebsd'):
         whichProc = subprocess.Popen(['which', 'scrot'], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
         SCROT_EXISTS = whichProc.wait() == 0
 except OSError as ex:
@@ -89,7 +89,7 @@ except OSError as ex:
         raise
 
 # On Linux, figure out which window system is being used.
-if sys.platform.startswith('linux'):
+if sys.platform.startswith('linux') or sys.platform.startswith('freebsd'):
     RUNNING_X11 = False
     RUNNING_WAYLAND = False
     if os.environ.get('XDG_SESSION_TYPE') == 'x11':
@@ -622,11 +622,11 @@ def _screenshot_linux(imageFilename=None, region=None)
         subprocess.call(['gnome-screenshot', '-f', tmpFilename])
     elif RUNNING_WAYLAND and SCROT_EXISTS and not GNOMESCREENSHOT_EXISTS:
         raise PyScreezeException(
-            'Your computer uses the Wayland window system. Scrot works on the X11 window system but not Wayland. You must install gnome-screenshot by running `sudo apt install gnome-screenshot`'  # noqa
+            'Your computer uses the Wayland window system. Scrot works on the X11 window system but not Wayland. You must install gnome-screenshot'  # noqa
         )
     else:
         raise Exception(
-            'To take screenshots, you must install Pillow version 9.2.0 or greater and gnome-screenshot by running `sudo apt install gnome-screenshot`'  # noqa
+            'To take screenshots, you must install Pillow version 9.2.0 or greater and gnome-screenshot'  # noqa
         )
 
     im = Image.open(tmpFilename)
@@ -772,7 +772,7 @@ elif sys.platform == 'win32':
     screenshot = _screenshot_osx
 elif sys.platform == 'win32':
     screenshot = _screenshot_win32
-elif sys.platform.startswith('linux'):
+elif sys.platform.startswith('linux') or sys.platform.startswith('freebsd'):
     # Everything else is considered to be Linux.
     screenshot = _screenshot_linux
 else:
