# Don't override window background color in order to
# avoid usability problems with light on dark themes
#
--- xpra/client/gtk_base/client_launcher.py.orig	2017-03-17 07:24:27 UTC
+++ xpra/client/gtk_base/client_launcher.py
@@ -143,7 +143,6 @@ class ApplicationWindow:
         self.window.set_default_size(400, 260)
         self.window.set_border_width(20)
         self.window.set_title("Xpra Launcher")
-        self.window.modify_bg(STATE_NORMAL, gdk.Color(red=65535, green=65535, blue=65535))
 
         icon_pixbuf = self.get_icon("xpra.png")
         if icon_pixbuf:
