--- tools/makeqpf/main.cpp.orig	Wed Jun 23 14:13:52 2004
+++ tools/makeqpf/main.cpp	Wed Aug 11 21:32:48 2004
@@ -124,8 +124,6 @@
     }
 };
 
-extern QString qws_topdir();
-
 class MakeQPF : public QMainWindow
 {
     Q_OBJECT
@@ -139,7 +137,7 @@
 	view->addColumn("Weight");
 	view->addColumn("Style");
 	setCentralWidget(view);
-	QString fontdir = qws_topdir() + "/lib/fonts";
+	QString fontdir = QString(getenv("QTDIR")) + "/lib/fonts";
 	readFontDir(fontdir);
 
 	connect(view,SIGNAL(selectionChanged(QListViewItem*)),
