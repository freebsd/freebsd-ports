--- src/FbTk/FbWindow.cc.orig	Sat Feb 14 10:48:03 2004
+++ src/FbTk/FbWindow.cc	Sat Feb 14 10:48:11 2004
@@ -168,7 +168,8 @@
     Window root;
     size_t border_width, depth;
     XGetGeometry(s_display, m_window, &root, &m_x, &m_y,
-                 &m_width, &m_height, &border_width, &depth);
+                (unsigned int*) &m_width, (unsigned int*) &m_height,
+				(unsigned int*) &border_width, (unsigned int*) &depth);
 }
 
 void FbWindow::create(Window parent, int x, int y,
