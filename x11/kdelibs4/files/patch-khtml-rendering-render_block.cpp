--- khtml/rendering/render_block.cpp	2004/03/01 04:46:27	1.20.2.6
+++ khtml/rendering/render_block.cpp	2004/04/26 21:05:27	1.20.2.7
@@ -422,14 +422,16 @@ void RenderBlock::layout()
 
 void RenderBlock::layoutBlock(bool relayoutChildren)
 {
+    if (isInline() && !isReplacedBlock()) {
+        setLayouted();
+        return;
+    }
+
     //    kdDebug( 6040 ) << renderName() << " " << this << "::layoutBlock() start" << endl;
     //     QTime t;
     //     t.start();
     KHTMLAssert( !layouted() );
     KHTMLAssert( minMaxKnown() );
-
-    if (isInline()) // Inline <form>s inside various table elements can cause us to
-        return;	    // come in here.  Just bail. -dwh
 
     int oldWidth = m_width;
 
