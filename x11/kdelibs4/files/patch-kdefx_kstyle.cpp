--- kdefx/kstyle.cpp.orig	19 Jun 2004 15:00:06 -0000	1.49
+++ kdefx/kstyle.cpp	19 Jun 2004 15:07:47 -0000
@@ -158,12 +158,16 @@ struct KStylePrivate
 	float menuOpacity;
 
 	TransparencyEngine   transparencyEngine;
 	KStyle::KStyleScrollBarType  scrollbarType;
 	TransparencyHandler* menuHandler;
 	KStyle::KStyleFlags flags;
+	
+	//For KPE_ListViewBranch
+	QBitmap *verticalLine;
+	QBitmap *horizontalLine;
 };
 
 // -----------------------------------------------------------------------------
 
 
 KStyle::KStyle( KStyleFlags flags, KStyleScrollBarType sbtype )
@@ -206,23 +210,28 @@ KStyle::KStyle( KStyleFlags flags, KStyl
 			// Create an instance of the menu transparency handler
 			d->menuOpacity = settings.readDoubleEntry("/KStyle/Settings/MenuOpacity", 0.90);
 			d->menuHandler = new TransparencyHandler(this, d->transparencyEngine,
 													 d->menuOpacity, d->menuDropShadow);
 		}
 	}
+	
+	d->verticalLine   = 0;
+	d->horizontalLine = 0;
 
 	// Create a transparency handler if only drop shadows are enabled.
 	if (!d->menuHandler && d->menuDropShadow)
 		d->menuHandler = new TransparencyHandler(this, Disabled, 1.0, d->menuDropShadow);
 }
 
 
 KStyle::~KStyle()
 {
-	if (d->menuHandler)
-		delete d->menuHandler;
+	delete d->verticalLine;
+	delete d->horizontalLine;
+
+	delete d->menuHandler;
 
 	d->menuHandler = NULL;
 	delete d;
 }
 
 
@@ -391,46 +400,40 @@ void KStyle::drawKStylePrimitive( KStyle
 			break;
 		}
 
 		case KPE_ListViewBranch: {
 			// Typical Windows style listview branch element (dotted line).
 
-			static QBitmap *verticalLine = 0, *horizontalLine = 0;
-			static QCleanupHandler<QBitmap> qlv_cleanup_bitmap;
-
 			// Create the dotline pixmaps if not already created
-			if ( !verticalLine )
+			if ( !d->verticalLine )
 			{
 				// make 128*1 and 1*128 bitmaps that can be used for
 				// drawing the right sort of lines.
-				verticalLine   = new QBitmap( 1, 129, true );
-				horizontalLine = new QBitmap( 128, 1, true );
+				d->verticalLine   = new QBitmap( 1, 129, true );
+				d->horizontalLine = new QBitmap( 128, 1, true );
 				QPointArray a( 64 );
 				QPainter p2;
-				p2.begin( verticalLine );
+				p2.begin( d->verticalLine );
 
 				int i;
 				for( i=0; i < 64; i++ )
 					a.setPoint( i, 0, i*2+1 );
 				p2.setPen( color1 );
 				p2.drawPoints( a );
 				p2.end();
 				QApplication::flushX();
-				verticalLine->setMask( *verticalLine );
+				d->verticalLine->setMask( *d->verticalLine );
 
-				p2.begin( horizontalLine );
+				p2.begin( d->horizontalLine );
 				for( i=0; i < 64; i++ )
 					a.setPoint( i, i*2+1, 0 );
 				p2.setPen( color1 );
 				p2.drawPoints( a );
 				p2.end();
 				QApplication::flushX();
-				horizontalLine->setMask( *horizontalLine );
-
-				qlv_cleanup_bitmap.add( &verticalLine );
-				qlv_cleanup_bitmap.add( &horizontalLine );
+				d->horizontalLine->setMask( *d->horizontalLine );
 			}
 
 			p->setPen( cg.text() );		// cg.dark() is bad for dark color schemes.
 
 			if (flags & Style_Horizontal)
 			{
@@ -441,13 +444,13 @@ void KStyle::drawKStylePrimitive( KStyle
 
 				while( point < end )
 				{
 					int i = 128;
 					if ( i+point > end )
 						i = end-point;
-					p->drawPixmap( point, other, *horizontalLine, 0, 0, i, thickness );
+					p->drawPixmap( point, other, *d->horizontalLine, 0, 0, i, thickness );
 					point += i;
 				}
 
 			} else {
 				int point = r.y();
 				int other = r.x();
@@ -457,13 +460,13 @@ void KStyle::drawKStylePrimitive( KStyle
 
 				while( point < end )
 				{
 					int i = 128;
 					if ( i+point > end )
 						i = end-point;
-					p->drawPixmap( other, point, *verticalLine, 0, pixmapoffset, thickness, i );
+					p->drawPixmap( other, point, *d->verticalLine, 0, pixmapoffset, thickness, i );
 					point += i;
 				}
 			}
 
 			break;
 		}
