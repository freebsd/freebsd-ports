--- plwm/outline.py.orig	2001-11-26 14:48:21.000000000 +0100
+++ plwm/outline.py	2009-06-06 17:47:13.000000000 +0200
@@ -63,7 +63,7 @@
 
 	if name:
 	    self.outline_gc.set_clip_rectangles(0, 0, [coords], X.YXSorted)
-	    sx, sy, sw, sh, as = namepos
+	    sx, sy, sw, sh, _as = namepos
 	    self.screen.root.draw_text(self.outline_gc, sx, sy, name)
 	    self.outline_name = (sx, sy, name)
 	else:
@@ -138,8 +138,8 @@
 			height = s[3] - s[1] + 1)
 
 	if name:
-	    sx, sy, sw, sh, as = namepos
-	    self.outline_name_window.configure(x = sx, y = sy - as,
+	    sx, sy, sw, sh, _as = namepos
+	    self.outline_name_window.configure(x = sx, y = sy - _as,
 					       width = sw, height = sh)
 	    
 	if not self.outline_mapped:
@@ -155,7 +155,7 @@
 	# disappear otherwise...
 	if name:
 	    self.outline_name_window.image_text(self.outline_name_gc,
-						0, as, name)
+						0, _as, name)
 	    
     def outline_hide(self):
 	if self.outline_mapped:
@@ -246,8 +246,8 @@
 
 	sw = min(r.overall_width, w)
 	sh = min(r.overall_ascent + r.overall_descent, h)
-	as = r.overall_ascent
+	_as = r.overall_ascent
     else:
-	sx = sy = sw = sh = as = 0
+	sx = sy = sw = sh = _as = 0
 
-    return (x, y, w, h), s, (sx, sy, sw, sh, as)
+    return (x, y, w, h), s, (sx, sy, sw, sh, _as)
