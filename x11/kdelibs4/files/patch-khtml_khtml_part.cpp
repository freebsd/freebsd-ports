--- khtml/khtml_part.cpp	2004/04/03 05:28:15	1.959.2.14
+++ khtml/khtml_part.cpp	2004/05/10 16:40:50	1.959.2.18
@@ -203,7 +203,7 @@ void KHTMLPart::init( KHTMLView *view, G
   d->m_paViewFrame = new KAction( i18n( "View Frame Source" ), 0, this, SLOT( slotViewFrameSource() ), actionCollection(), "viewFrameSource" );
   d->m_paViewInfo = new KAction( i18n( "View Document Information" ), CTRL+Key_I, this, SLOT( slotViewPageInfo() ), actionCollection(), "viewPageInfo" );
   d->m_paSaveBackground = new KAction( i18n( "Save &Background Image As..." ), 0, this, SLOT( slotSaveBackground() ), actionCollection(), "saveBackground" );
-  d->m_paSaveDocument = new KAction( i18n( "&Save As..." ), CTRL+Key_S, this, SLOT( slotSaveDocument() ), actionCollection(), "saveDocument" );
+  d->m_paSaveDocument = KStdAction::saveAs( this, SLOT( slotSaveDocument() ), actionCollection(), "saveDocument" );
   if ( parentPart() )
       d->m_paSaveDocument->setShortcut( KShortcut() ); // avoid clashes
   d->m_paSaveFrame = new KAction( i18n( "Save &Frame As..." ), 0, this, SLOT( slotSaveFrame() ), actionCollection(), "saveFrame" );
@@ -332,7 +332,7 @@ void KHTMLPart::init( KHTMLView *view, G
       d->m_paFindNext->setShortcut( KShortcut() ); // avoid clashes
   }
 
-  d->m_paPrintFrame = new KAction( i18n( "Print Frame" ), "frameprint", 0, this, SLOT( slotPrintFrame() ), actionCollection(), "printFrame" );
+  d->m_paPrintFrame = new KAction( i18n( "Print Frame..." ), "frameprint", 0, this, SLOT( slotPrintFrame() ), actionCollection(), "printFrame" );
   d->m_paPrintFrame->setWhatsThis( i18n( "Print Frame<p>"
 					 "Some pages have several frames. To print only a single frame, click "
 					 "on it and then use this function." ) );
@@ -2665,7 +2665,7 @@ void KHTMLPart::findTextNext()
 	    d->m_find->setPattern( d->m_findDialog->pattern() );
 	    d->m_find->resetCounts();
     }
-    long options = d->m_findDialog->options();
+    options = d->m_findDialog->options();
     if ( d->m_lastFindState.options != options )
     {
       d->m_find->setOptions( options );
@@ -2712,7 +2712,7 @@ void KHTMLPart::findTextNext()
       {
         // Grab text from render object
         QString s;
-        bool renderAreaText = (QCString(obj->parent()->renderName())== "RenderTextArea");
+        bool renderAreaText = obj->parent() && (QCString(obj->parent()->renderName())== "RenderTextArea");
         bool renderLineText = (QCString(obj->renderName())== "RenderLineEdit");
         if ( renderAreaText )
         {
@@ -3288,7 +3288,7 @@ void KHTMLPart::urlSelected( const QStri
 
   kdDebug( 6000 ) << "urlSelected: complete URL:" << cURL.url() << " target = " << target << endl;
 
-  if ( button == LeftButton && (state & ControlButton) )
+  if ( state & ControlButton )
   {
     args.setNewTab(true);
     emit d->m_extension->createNewWindow( cURL, args );
