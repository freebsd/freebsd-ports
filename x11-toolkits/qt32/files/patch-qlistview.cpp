--- src/widgets/qlistview.cpp.orig	Mon Feb 24 09:30:39 2003
+++ src/widgets/qlistview.cpp	Mon May 12 19:42:07 2003
@@ -6215,7 +6215,7 @@
 
 void QListView::ensureItemVisible( const QListViewItem * i )
 {
-    if ( !i )
+    if ( !i || !i->isVisible() )
 	return;
 
     QListViewItem *parent = i->parent();
