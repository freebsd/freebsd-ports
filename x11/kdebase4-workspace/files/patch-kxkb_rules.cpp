===================================================================
RCS file: /usr/repos/kde/kdebase/kxkb/rules.cpp,v
retrieving revision 1.37
retrieving revision 1.38
diff -u -p -r1.37 -r1.38
--- kxkb/rules.cpp	2003/10/24 06:15:26	1.37
+++ kxkb/rules.cpp	2004/06/28 14:19:03	1.38
@@ -16,11 +16,23 @@
 
 #include "rules.h"
 
-const QString X11_DIR( "/usr/X11R6/lib/X11/" );
+const char* X11DirList[2] = {"/usr/X11R6/lib/X11/", "/usr/local/X11R6/lib/X11/"};
+const char* rulesFileList[2] = {"xkb/rules/xfree86", "xkb/rules/xorg"};
 
-KeyRules::KeyRules(QString rule):
+KeyRules::KeyRules():
     m_layouts(90)
 {
+  for(int ii=0; ii<2; ii++)
+    if( QDir(X11DirList[ii]).exists() ) {
+	X11_DIR = X11DirList[ii];
+	break;
+    }
+
+  if( X11_DIR.isEmpty() ) {
+    kdDebug() << "Cannot find X11 directory!" << endl;
+    return;
+  }
+
   // ugly check for XFree 4.3 or older
   if( QDir(X11_DIR + "xkb/symbols/pc").exists() ) {
 	m_xfree43 = true;
@@ -29,8 +41,20 @@ KeyRules::KeyRules(QString rule):
 	m_xfree43 = false;
   }
 
-  loadRules(X11_DIR + QString("xkb/rules/%1").arg(rule));
-  loadOldLayouts(X11_DIR + QString("xkb/rules/xfree86"));
+  QString rulesFile;
+  for(int ii=0; ii<2; ii++)
+    if( QFile(X11_DIR + QString(rulesFileList[ii])).exists() ) {
+	rulesFile = X11_DIR + rulesFileList[ii];
+	break;
+    }
+
+  if( rulesFile.isEmpty() ) {
+    kdDebug() << "Cannot find rules file in " << X11_DIR << endl;
+    return;
+  }
+
+  loadRules(rulesFile);
+  loadOldLayouts(rulesFile);
   loadGroups(::locate("config", "kxkb_groups"));
 }
 
@@ -51,9 +75,7 @@ static struct {
     { 0, 0 }
 };
 
-  XkbRF_RulesPtr rules;
-
-  rules = XkbRF_Load(QFile::encodeName(file).data(), "", true, true);
+  XkbRF_RulesPtr rules = XkbRF_Load(QFile::encodeName(file).data(), "", true, true);
 
   if (rules == NULL) {
      kdDebug() << "Unable to load rules" << endl;
@@ -176,7 +198,7 @@ unsigned int KeyRules::getGroup(const QS
     return it == m_initialGroups.end() ? 0 : it.data();
 }
 
-
+/*
 QStringList KeyRules::rules(QString path)
 {
   QStringList result;
@@ -193,7 +215,7 @@ QStringList KeyRules::rules(QString path
 
   return result;
 }
-
+*/
 
 /* pretty simple algorithm - reads the layout file and
     tries to find "xkb_symbols"
