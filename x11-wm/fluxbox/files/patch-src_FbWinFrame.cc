--- src/FbWinFrame.cc.orig	2015-02-08 10:44:45 UTC
+++ src/FbWinFrame.cc
@@ -115,8 +115,8 @@ FbWinFrame::FbWinFrame(BScreen &screen, unsigned int c
     m_state(state),
     m_window(theme->screenNum(), state.x, state.y, state.width, state.height, s_mask, true, false,
         client_depth, InputOutput,
-        ((client_depth == 32) && (screen.rootWindow().depth() == 32) ? screen.rootWindow().visual() : CopyFromParent),
-        ((client_depth == 32) && (screen.rootWindow().depth() == 32) ? screen.rootWindow().colormap() : CopyFromParent)),
+        (client_depth == screen.rootWindow().maxDepth() ? screen.rootWindow().visual() : CopyFromParent),
+        (client_depth == screen.rootWindow().maxDepth() ? screen.rootWindow().colormap() : CopyFromParent)),
     m_layeritem(window(), *screen.layerManager().getLayer(ResourceLayer::NORMAL)),
     m_titlebar(m_window, 0, 0, 100, 16, s_mask, false, false, 
         screen.rootWindow().decorationDepth(), InputOutput,
