--- include/wx/menuitem.h.orig Wed Aug 27 21:11:09 2003
+++ include/wx/menuitem.h      Wed Aug 27 21:11:35 2003
@@ -4,7 +4,7 @@
 // Author:      Vadim Zeitlin
 // Modified by:
 // Created:     25.10.99
-// RCS-ID:      $Id: menuitem.h,v 1.22 2002/04/12 13:15:43 JS Exp $
+// RCS-ID:      $Id: menuitem.h,v 1.22.2.1 2003/06/10 23:48:45 RD Exp $
 // Copyright:   (c) 1999 Vadim Zeitlin <zeitlin@dptmaths.ens-cachan.fr>
 // Licence:     wxWindows license
 ///////////////////////////////////////////////////////////////////////////////
@@ -49,6 +49,7 @@

     // the menu we're in
     wxMenu *GetMenu() const { return m_parentMenu; }
+    void SetMenu(wxMenu* menu) { m_parentMenu = menu; }

     // get/set id
     void SetId(int id) { m_id = id; }
