--- kxkb/rules.cpp	2004/06/28 14:19:03	1.38
+++ kxkb/rules.cpp	2004/10/10 22:59:59	1.38.2.1
@@ -1,3 +1,4 @@
+#include <qwindowdefs.h>
 #include <qfile.h>
 #include <qtextstream.h>
 #include <qregexp.h>
@@ -42,11 +43,19 @@ KeyRules::KeyRules():
   }
 
   QString rulesFile;
-  for(int ii=0; ii<2; ii++)
+  Display *dpy = qt_xdisplay();
+  XkbRF_VarDefsRec vd;
+  char *tmp= NULL;
+  if (XkbRF_GetNamesProp(dpy,&tmp,&vd) && tmp) 
+    rulesFile = X11_DIR + QString("xkb/rules/%1").arg(tmp);
+  else {
+    // old way
+    for(int ii=0; ii<2; ii++)
     if( QFile(X11_DIR + QString(rulesFileList[ii])).exists() ) {
 	rulesFile = X11_DIR + rulesFileList[ii];
 	break;
     }
+  }
 
   if( rulesFile.isEmpty() ) {
     kdDebug() << "Cannot find rules file in " << X11_DIR << endl;
