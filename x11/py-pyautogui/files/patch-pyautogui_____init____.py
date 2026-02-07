--- pyautogui/__init__.py.orig	2025-07-05 19:46:17 UTC
+++ pyautogui/__init__.py
@@ -540,7 +540,7 @@ elif sys.platform == "win32":
     from . import _pyautogui_osx as platformModule
 elif sys.platform == "win32":
     from . import _pyautogui_win as platformModule
-elif platform.system() == "Linux":
+elif platform.system() == "Linux" or platform.system() == "FreeBSD":
     from . import _pyautogui_x11 as platformModule
 else:
     raise NotImplementedError("Your platform (%s) is not supported by PyAutoGUI." % (platform.system()))
@@ -848,8 +848,8 @@ def _normalizeButton(button):
 
     # Check that `button` has a valid value:
     button = button.lower()
-    if platform.system() == "Linux":
-        # Check for valid button arg on Linux:
+    if platform.system() == "Linux" or platform.system() == "FreeBSD":
+        # Check for valid button arg on FreeBSD/Linux:
         if button not in (LEFT, MIDDLE, RIGHT, PRIMARY, SECONDARY, 1, 2, 3, 4, 5, 6, 7):
             raise PyAutoGUIException(
                 "button argument must be one of ('left', 'middle', 'right', 'primary', 'secondary', 1, 2, 3, 4, 5, 6, 7)"
@@ -1125,7 +1125,7 @@ def doubleClick(x=None, y=None, interval=0.0, button=L
         platformModule._multiClick(x, y, button, 2)
         _logScreenshot(logScreenshot, 'click', '%s,%s,%s,2' % (x, y, button), folder='.')
     else:
-        # Click for Windows or Linux:
+        # Click for Windows, FreeBSD or Linux:
         click(x, y, 2, interval, button, duration, tween, logScreenshot, _pause=False)
 
 
@@ -1167,7 +1167,7 @@ def tripleClick(x=None, y=None, interval=0.0, button=L
         _logScreenshot(logScreenshot, "click", "%s,%s,%s,3" % (x, y, button), folder=".")
         platformModule._multiClick(x, y, button, 3)
     else:
-        # Click for Windows or Linux:
+        # Click for Windows, FreeBSD or Linux:
         click(x, y, 3, interval, button, duration, tween, logScreenshot, _pause=False)
 
 
