--- src/widgets/qtextedit.cpp.orig	Mon Feb 24 09:30:37 2003
+++ src/widgets/qtextedit.cpp	Mon May 12 19:50:19 2003
@@ -1863,7 +1863,7 @@
     }
     setModified();
     emit textChanged();
-    emit selectionChanged();
+    emit copyAvailable( doc->hasSelection( QTextDocument::Standard ) );
 }
 
 /*!
@@ -4801,7 +4801,7 @@
 	return;
     if ( doc->hasSelection( QTextDocument::Standard ) )
 	removeSelectedText();
-    if ( !m->provides( st.data() ) )
+    if ( !QRichTextDrag::canDecode( m ) )
 	return;
     QString t;
     if ( !QRichTextDrag::decode( m, t, st.data(), subtype ) )
