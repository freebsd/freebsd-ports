===================================================================
RCS file: /usr/repos/kde/kdebase/kxkb/rules.h,v
retrieving revision 1.11
retrieving revision 1.12
diff -u -p -r1.11 -r1.12
--- kxkb/rules.h	2003/08/24 04:02:38	1.11
+++ kxkb/rules.h	2004/06/28 14:19:03	1.12
@@ -10,14 +10,14 @@ class KeyRules
 {
 public:
 
-  KeyRules(QString rule="xfree86");
+  KeyRules();
 
   const QDict<char> &models() const { return m_models; };
   const QDict<char> &layouts() const { return m_layouts; };
   const QDict<char> &options() const { return m_options; };
 
   void parseVariants(const QStringList& vars, QDict<char>& variants, bool chkVars=true);
-  static QStringList rules(QString path = QString::null);
+//  static QStringList rules(QString path = QString::null);
 
   QStringList getVariants(const QString& layout);
   unsigned int getGroup(const QString& layout, const char* baseGr);
@@ -42,6 +42,8 @@ private:
   QStringList m_oldLayouts;
   QStringList m_nonLatinLayouts;
   bool m_xfree43;
+  
+  QString X11_DIR;	// pseudo-constant
 };
 
 
