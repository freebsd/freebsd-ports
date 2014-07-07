--- GUI/Gtk/GL.py.orig	2014-06-26 13:52:22.944073560 -0300
+++ GUI/Gtk/GL.py	2014-06-26 13:52:54.997070771 -0300
@@ -42,13 +42,13 @@
     
     def _gtk_get_config(self):
         cs = self._color_size
-        as = 0
+        _as = 0
         ds = 0
         ss = 0
         acs = 0
         aas = 0
         if self._alpha:
-            as = self._alpha_size
+            _as = self._alpha_size
         if self._depth_buffer:
             ds = self._depth_size
         if self._stencil_buffer:
@@ -62,7 +62,7 @@
             gdkgl.RED_SIZE, cs,
             gdkgl.GREEN_SIZE, cs,
             gdkgl.BLUE_SIZE, cs,
-            gdkgl.ALPHA_SIZE, as,
+            gdkgl.ALPHA_SIZE, _as,
             gdkgl.AUX_BUFFERS, self._aux_buffers,
             gdkgl.DEPTH_SIZE, ds,
             gdkgl.STENCIL_SIZE, ss,
@@ -223,4 +223,4 @@
         print "GLPixmap: Set viewport to", width, height ###
         self.init_context()
