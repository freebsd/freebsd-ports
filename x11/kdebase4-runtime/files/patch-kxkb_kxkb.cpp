===================================================================
RCS file: /usr/repos/kde/kdebase/kxkb/kxkb.cpp,v
retrieving revision 1.70
retrieving revision 1.72
diff -u -p -r1.70 -r1.72
--- kxkb/kxkb.cpp	2003/10/30 18:58:11	1.70
+++ kxkb/kxkb.cpp	2004/06/28 14:19:03	1.72
@@ -222,12 +222,12 @@ bool KXKBApp::settingsRead()
 	}
     }
 
-    QString rule = "xfree86"; //config->readEntry("Rule", "xfree86");
-    m_rules = new KeyRules( rule );
+    m_rules = new KeyRules();
     m_model = config->readEntry("Model", "pc104");
     m_layout = config->readEntry("Layout", "");
     m_defaultLayout = m_layout;
 
+
     m_list = config->readListEntry("Additional");
     if (!m_list.contains(m_layout))
     {

