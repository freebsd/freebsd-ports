--- src/main.c.orig	Sun Oct  1 23:50:39 2006
+++ src/main.c	Sat Jun 16 23:10:08 2007
@@ -562,6 +562,17 @@
 #  endif
 # endif
 
+    if( NOT_NULL( r->h->appIcon ) )
+    {
+        XFreePixmap (r->Xdisplay, r->h->appIcon);
+        SET_NULL(r->h->appIcon);
+    }
+    if( NOT_NULL( r->h->appIconMask ) )
+    {
+        XFreePixmap (r->Xdisplay, r->h->appIconMask);
+        SET_NULL(r->h->appIconMask);
+    }
+
     if (IS_CURSOR(r->term_pointer))
     {
 	XFreeCursor (r->Xdisplay, r->term_pointer);
@@ -599,6 +610,7 @@
 	SET_NULL(r->xftColors);
     }
 # endif
+
     rxvt_free (r->h);		    SET_NULL(r->h);
     rxvt_free (r);		    SET_NULL(r);
 
