--- customtkinter/windows/widgets/appearance_mode/appearance_mode_tracker.py.orig	2024-08-11 19:14:14 UTC
+++ customtkinter/windows/widgets/appearance_mode/appearance_mode_tracker.py
@@ -1,6 +1,6 @@ from typing import Callable
 import tkinter
 from typing import Callable
-import darkdetect
+#import darkdetect
 
 
 class AppearanceModeTracker:
@@ -45,7 +45,7 @@ class AppearanceModeTracker:
     @staticmethod
     def detect_appearance_mode() -> int:
         try:
-            if darkdetect.theme() == "Dark":
+            if True:
                 return 1  # Dark
             else:
                 return 0  # Light
