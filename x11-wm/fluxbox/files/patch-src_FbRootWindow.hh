--- src/FbRootWindow.hh.orig	2015-02-08 10:44:45 UTC
+++ src/FbRootWindow.hh
@@ -41,6 +41,7 @@ class FbRootWindow: public FbTk::FbWindow { (public)
     int decorationDepth() const { return m_decorationDepth; }
     Visual *decorationVisual() const { return m_decorationVisual; }
     Colormap decorationColormap() const { return m_decorationColormap; }
+    int maxDepth() const { return m_maxDepth; }
 
 private:
     Visual *m_visual;
@@ -49,6 +50,7 @@ class FbRootWindow: public FbTk::FbWindow { (public)
     int m_decorationDepth;
     Visual *m_decorationVisual;
     Colormap m_decorationColormap;
+    int m_maxDepth;
 };
 
 #endif // FBROOTWINDOW_HH
