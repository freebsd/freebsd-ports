--- src/widgets/qpopupmenu.cpp.orig	Mon May 12 19:44:39 2003
+++ src/widgets/qpopupmenu.cpp	Mon May 12 19:45:42 2003
@@ -1739,7 +1739,7 @@
 	if ( style().styleHint(QStyle::SH_PopupMenu_SloppySubMenus, this) &&
 	     d->mouseMoveBuffer.contains( e->pos() ) ) {
 	    actItem = item;
-	    popupSubMenuLater( style().styleHint(QStyle::SH_PopupMenu_SubMenuPopupDelay, this) * 2,
+	    popupSubMenuLater( style().styleHint(QStyle::SH_PopupMenu_SubMenuPopupDelay, this) * 6,
 			       this );
 	    return;
 	}
