--- khtml/rendering/render_root.cpp	16 Jul 2003 00:13:32 -0000	1.116.2.3
+++ khtml/rendering/render_root.cpp	2 Aug 2003 21:28:49 -0000	1.116.2.4
@@ -118,7 +118,7 @@ void RenderRoot::layout()
 #endif
     if (!m_printingMode) {
         QSize s = m_view->viewportSize(m_view->contentsWidth(),
-                                       0);
+                                       m_view->contentsHeight());
         m_width = s.width();
         m_height = s.height();
     }
@@ -132,7 +132,7 @@ void RenderRoot::layout()
     if (!m_printingMode) {
         m_view->resizeContents(docWidth(), docHeight());
         QSize s = m_view->viewportSize(m_view->contentsWidth(),
-                                       m_view->contentsHeight());
+                                       0);
         setWidth( m_viewportWidth = s.width() );
         setHeight(  m_viewportHeight = s.height() );
     }
