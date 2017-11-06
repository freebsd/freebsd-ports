# Don't override window background colors in order to
# avoid usability problems with light on dark themes
#
--- xpra/client/gtk_base/bug_report.py.orig	2017-03-17 07:24:27 UTC
+++ xpra/client/gtk_base/bug_report.py
@@ -43,7 +43,6 @@ class BugReport(object):
         self.window.set_default_size(400, 300)
         self.window.set_border_width(20)
         self.window.set_title("Xpra Bug Report")
-        self.window.modify_bg(STATE_NORMAL, gdk.Color(red=65535, green=65535, blue=65535))
 
         icon_pixbuf = self.get_icon("bugs.png")
         if icon_pixbuf:
@@ -89,7 +88,6 @@ class BugReport(object):
         self.description.set_justification(JUSTIFY_LEFT)
         self.description.set_border_width(2)
         self.description.set_size_request(300, 80)
-        self.description.modify_bg(STATE_NORMAL, gdk.Color(red=32768, green=32768, blue=32768))
         ibox.pack_start(self.description, expand=False, fill=False)
 
         # Toggles:
