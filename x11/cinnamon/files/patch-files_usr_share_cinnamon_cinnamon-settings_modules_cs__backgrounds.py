--- files/usr/share/cinnamon/cinnamon-settings/modules/cs_backgrounds.py.orig	2024-01-04 18:09:30 UTC
+++ files/usr/share/cinnamon/cinnamon-settings/modules/cs_backgrounds.py
@@ -576,7 +576,7 @@ class PixCache(object):
     def get_pix(self, filename, size=None):
         if filename is None:
             return None
-        mimetype = mimetypes.guess_type(filename)[0]
+        mimetype = mimetypes.guess_type(filename, strict=False)[0]
         if mimetype is None or not mimetype.startswith("image/"):
             return None
 
