--- kdeui/klanguagebutton.cpp.orig	Tue Sep 14 18:00:28 2004
+++ kdeui/klanguagebutton.cpp	Tue Sep 14 18:00:46 2004
@@ -104,6 +104,7 @@
 
 void KLanguageButton::init(const char * name)
 {
+  m_current = 0;
   m_ids = new QStringList;
   m_popup = 0;
   m_oldPopup = 0;
