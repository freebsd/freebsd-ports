--- contrib/src/gizmos/multicell.cpp.orig	Wed Nov  5 00:04:44 2003
+++ contrib/src/gizmos/multicell.cpp	Wed Nov  5 00:06:11 2003
@@ -633,17 +633,12 @@
 	m_minCellSize = wxSize(5, 5);
 }
 //---------------------------------------------------------------------------
-wxString itoa(int x)
-{
-	char    bfr[255];
-	sprintf(bfr, "%d", x);
-	return bfr;
-}
-//---------------------------------------------------------------------------
 void wxMultiCellCanvas :: Add(wxWindow *win, unsigned int row, unsigned int col)
 {
-	wxASSERT_MSG(row >= 0 && row < m_maxRows, wxString("Row ") + itoa(row) + " out of bounds (" + itoa(m_maxRows) + ")");
-	wxASSERT_MSG(col >= 0 && col < m_maxCols, wxString("Column ") + itoa(col) + " out of bounds (" + itoa(m_maxCols) + ")");
+	wxASSERT_MSG(row >= 0 && row < m_maxRows,
+		wxString::Format(_T("Row %d out of bounds (0..%d)"), row, m_maxRows) );
+	wxASSERT_MSG(col >= 0 && col < m_maxCols,
+		wxString::Format(_T("Column %d out of bounds (0..%d)"), col, m_maxCols) );
 	wxASSERT_MSG(m_cells[CELL_LOC(row, col)] == NULL, wxT("Cell already occupied"));
 
 	wxCell *newCell = new wxCell(win);
@@ -660,7 +655,7 @@
 			if (!m_cells[CELL_LOC(row, col)])
 			{
 				// Create an empty static text field as a placeholder
-				m_cells[CELL_LOC(row, col)] = new wxCell(new wxStaticText(m_parent, -1, ""));
+				m_cells[CELL_LOC(row, col)] = new wxCell(new wxStaticText(m_parent, -1, wxT("")));
 			}
 			wxFlexGridSizer::Add(m_cells[CELL_LOC(row, col)]->m_window);
 		}
