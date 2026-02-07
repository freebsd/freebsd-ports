--- src/mouseinfo/__init__.py.orig	2025-07-05 20:10:22 UTC
+++ src/mouseinfo/__init__.py
@@ -203,7 +203,7 @@ elif sys.platform == 'darwin':
     getPixel = _macGetPixel
 
 
-elif platform.system() == 'Linux':
+elif platform.system() == 'Linux' or platform.system() == 'FreeBSD':
     from Xlib.display import Display
     import errno
 
@@ -229,7 +229,7 @@ elif platform.system() == 'Linux':
 
     def _linuxScreenshot(filename=None):
         if not scrotExists:
-            raise NotImplementedError('"scrot" must be installed to use screenshot functions in Linux. Run: sudo apt-get install scrot')
+            raise NotImplementedError('"scrot" must be installed to use screenshot functions in FreeBSD/Linux.')
 
         if filename is not None:
             tmpFilename = filename
@@ -247,7 +247,7 @@ elif platform.system() == 'Linux':
                 os.unlink(tmpFilename)
             return im
         else:
-            raise Exception('The scrot program must be installed to take a screenshot with PyScreeze on Linux. Run: sudo apt-get install scrot')
+            raise Exception('The scrot program must be installed to take a screenshot with PyScreeze on FreeBSD/Linux')
     screenshot = _linuxScreenshot
 
     def _linuxSize():
@@ -262,14 +262,14 @@ RUNNING_PYTHON_2 = sys.version_info[0] == 2
 
 RUNNING_PYTHON_2 = sys.version_info[0] == 2
 
-if platform.system() == 'Linux':
+if platform.system() == 'Linux' or platform.system() == 'FreeBSD':
     if RUNNING_PYTHON_2:
         try:
             import Tkinter as tkinter
             ttk = tkinter
             from Tkinter import Event
         except ImportError:
-            sys.exit('NOTE: You must install tkinter on Linux to use MouseInfo. Run the following: sudo apt-get install python-tk python-dev')
+            sys.exit('NOTE: You must install tkinter on FreeBSD/Linux to use MouseInfo.')
     else:
         # Running Python 3+:
         try:
@@ -277,7 +277,7 @@ if platform.system() == 'Linux':
             from tkinter import ttk
             from tkinter import Event
         except ImportError:
-            sys.exit('NOTE: You must install tkinter on Linux to use MouseInfo. Run the following: sudo apt-get install python3-tk python3-dev')
+            sys.exit('NOTE: You must install tkinter on FreeBSD/Linux to use MouseInfo.')
 else:
     # Running Windows or macOS:
     if RUNNING_PYTHON_2:
@@ -358,8 +358,8 @@ class MouseInfoWindow:
             pyperclip.copy(textToCopy)
             self.statusbarSV.set('Copied ' + textToCopy)
         except pyperclip.PyperclipException as e:
-            if platform.system() == 'Linux':
-                self.statusbarSV.set('Copy failed. Run "sudo apt-get install xsel".')
+            if platform.system() == 'Linux' or platform.system() == 'FreeBSD':
+                self.statusbarSV.set('Copy failed. You must nstall xsel".')
             else:
                 self.statusbarSV.set('Clipboard error: ' + str(e))
 
