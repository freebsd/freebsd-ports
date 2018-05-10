--- src/FbRootWindow.cc.orig	2015-02-08 10:44:45 UTC
+++ src/FbRootWindow.cc
@@ -30,7 +30,8 @@ FbRootWindow::FbRootWindow(int screen_num):
     m_colormap(0),
     m_decorationDepth(0),
     m_decorationVisual(0),
-    m_decorationColormap(0) {
+    m_decorationColormap(0),
+    m_maxDepth(depth()) {
 
     Display *disp = FbTk::App::instance()->display();
 
@@ -55,9 +56,9 @@ FbRootWindow::FbRootWindow(int screen_num):
 
         for (int i = 0; i < vinfo_nitems; i++) {
             if ((DefaultDepth(disp, screen_num) < vinfo_return[i].depth)
-                    && (static_cast<int>(depth()) < vinfo_return[i].depth)){
+                    && (m_maxDepth < vinfo_return[i].depth)){
                 m_visual = vinfo_return[i].visual;
-                setDepth(vinfo_return[i].depth);
+                m_maxDepth = vinfo_return[i].depth;
             }
 
             if((m_decorationDepth < vinfo_return[i].depth)
