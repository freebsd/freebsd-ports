--- khtml/khtml_part.cpp.orig	Mon Mar  1 09:25:09 2004
+++ khtml/khtml_part.cpp	Sat Mar 13 20:48:58 2004
@@ -5395,7 +5395,7 @@
       pix = KMimeType::pixmapForURL(u, 0, KIcon::Desktop, KIcon::SizeMedium);
     }
 
-    KURLDrag* urlDrag = new KURLDrag( u, 0 );
+    KURLDrag* urlDrag = new KURLDrag( u, img ? 0 : d->m_view->viewport() );
     if ( !d->m_referrer.isEmpty() )
       urlDrag->metaData()["referrer"] = d->m_referrer;
 
