--- src/kernel/qrichtext.cpp	2004/08/11 14:21:12	1.68
+++ src/kernel/qrichtext.cpp	2004/09/07 09:10:27	1.71
@@ -3801,6 +3801,7 @@ void QTextString::checkBidi() const
 
     // determines the properties we need for layouting
     QTextEngine textEngine( toString(), 0 );
+    textEngine.direction = (QChar::Direction) dir;
     textEngine.itemize(QTextEngine::SingleLine);
     const QCharAttributes *ca = textEngine.attributes() + length-1;
     QTextStringChar *ch = (QTextStringChar *)end - 1;
@@ -3835,7 +3836,7 @@ void QTextString::checkBidi() const
     } else if ( dir == QChar::DirL ) {
 	that->rightToLeft = FALSE;
     } else {
-	that->rightToLeft = (textEngine.items[0].analysis.bidiLevel % 2);
+	that->rightToLeft = (textEngine.direction == QChar::DirR);
     }
 }
 
@@ -4510,6 +4510,8 @@ void QTextParagraph::paint( QPainter &pa
 	fullSelectionWidth = (hasdoc ? document()->width() : r.width());
 
     QString qstr = str->toString();
+    // detach string
+    qstr.setLength(qstr.length());
     // ### workaround so that \n are not drawn, actually this should
     // be fixed in QFont somewhere (under Windows you get ugly boxes
     // otherwise)
@@ -5310,7 +5312,7 @@ QTextLineStart *QTextFormatter::formatLi
 #endif
 
 // collects one line of the paragraph and transforms it to visual order
-QTextLineStart *QTextFormatter::bidiReorderLine( QTextParagraph * /*parag*/, QTextString *text, QTextLineStart *line,
+QTextLineStart *QTextFormatter::bidiReorderLine( QTextParagraph * parag, QTextString *text, QTextLineStart *line,
 							QTextStringChar *startChar, QTextStringChar *lastChar, int align, int space )
 {
     // ignore white space at the end of the line.
@@ -5404,6 +5406,7 @@ QTextLineStart *QTextFormatter::bidiReor
 	}
 
  	ch->x = x + toAdd;
+	ch->rightToLeft = ch->bidiLevel % 2;
 	//qDebug("visual: %d (%p) placed at %d rightToLeft=%d", visual[i], ch, x +toAdd, ch->rightToLeft  );
 	int ww = 0;
 	if ( ch->c.unicode() >= 32 || ch->c == '\t' || ch->c == '\n' || ch->isCustom() ) {
@@ -5419,12 +5422,14 @@ QTextLineStart *QTextFormatter::bidiReor
     while ( endSpaces-- ) {
 	++lastChar;
 	int sw = lastChar->format()->width( ' ' );
-	if ( lastChar->rightToLeft ) {
+	if ( text->isRightToLeft() ) {
 	    xorig -= sw;
 	    lastChar->x = xorig;
+	    ch->rightToLeft = TRUE;
 	} else {
 	    lastChar->x = x;
 	    x += sw;
+	    ch->rightToLeft = FALSE;
 	}
     }
 
