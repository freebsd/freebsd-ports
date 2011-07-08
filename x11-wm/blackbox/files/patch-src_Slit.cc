--- src/Slit.cc.orig	2005-01-04 20:58:33.000000000 +0800
+++ src/Slit.cc	2011-06-21 13:31:00.000000000 +0800
@@ -248,6 +248,13 @@
     bt::PixmapCache::find(screen->screenNumber(), texture,
                           frame.rect.width(), frame.rect.height(),
                           frame.pixmap);
+
+  if ((texture.texture() & bt::Texture::Gradient) && frame.pixmap)
+    XSetWindowBackgroundPixmap(display, frame.window, frame.pixmap);
+  else if ((texture.texture() & bt::Texture::Solid))
+    XSetWindowBackground(display, frame.window,
+      texture.color1().pixel(screen->screenNumber()));
+
   XClearArea(display, frame.window, 0, 0,
              frame.rect.width(), frame.rect.height(), True);
 
