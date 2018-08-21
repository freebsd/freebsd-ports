--- src/Slit.cc.orig	2005-01-04 12:58:33 UTC
+++ src/Slit.cc
@@ -248,6 +248,13 @@ void Slit::reconfigure(void) {
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
 
