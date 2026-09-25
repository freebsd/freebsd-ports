--- kitty/shaders/custom/demo.py.orig	1979-11-29 23:00:00 UTC
+++ kitty/shaders/custom/demo.py
@@ -13,6 +13,8 @@ from typing import Any
 from threading import Thread
 from typing import Any
 
+sys.path.insert(0, '%%DATADIR%%')
+
 from kitty.constants import glfw_path
 from kitty.fast_data_types import GLFW_FKEY_ESCAPE as KEY_ESCAPE
 from kitty.fast_data_types import GLFW_MOUSE_BUTTON_LEFT as MOUSE_BUTTON_LEFT
