--- contrib/src/plot/plot.cpp.orig	Wed Nov  5 00:03:37 2003
+++ contrib/src/plot/plot.cpp	Wed Nov  5 00:04:27 2003
@@ -204,7 +204,7 @@
 END_EVENT_TABLE()
 
 wxPlotArea::wxPlotArea( wxPlotWindow *parent )
-        : wxWindow( parent, -1, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, "plotarea" )
+        : wxWindow( parent, -1, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("plotarea") )
 {
     m_owner = parent;
     
@@ -462,7 +462,7 @@
 END_EVENT_TABLE()
 
 wxPlotXAxisArea::wxPlotXAxisArea( wxPlotWindow *parent )
-        : wxWindow( parent, -1, wxDefaultPosition, wxSize(-1,40), 0, "plotxaxisarea" )
+        : wxWindow( parent, -1, wxDefaultPosition, wxSize(-1,40), 0, _T("plotxaxisarea") )
 {
     m_owner = parent;
     
@@ -589,7 +589,7 @@
 END_EVENT_TABLE()
 
 wxPlotYAxisArea::wxPlotYAxisArea( wxPlotWindow *parent )
-        : wxWindow( parent, -1, wxDefaultPosition, wxSize(60,-1), 0, "plotyaxisarea" )
+        : wxWindow( parent, -1, wxDefaultPosition, wxSize(60,-1), 0, _T("plotyaxisarea") )
 {
     m_owner = parent;
     
@@ -713,7 +713,7 @@
 END_EVENT_TABLE()
 
 wxPlotWindow::wxPlotWindow( wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size, int flag )
-        : wxScrolledWindow( parent, id, pos, size, flag, "plotcanvas" )
+        : wxScrolledWindow( parent, id, pos, size, flag, _T("plotcanvas") )
 {
     m_xUnitsPerValue = 1.0;
     m_xZoom = 1.0;
