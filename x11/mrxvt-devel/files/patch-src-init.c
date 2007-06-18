--- src/init.c.orig	Sat Jun 16 23:26:00 2007
+++ src/init.c	Sat Jun 16 23:26:19 2007
@@ -41,7 +41,7 @@
 # define DEBUG_X
 #else
 # define DEBUG_LEVEL	0
-# define DEBUG_X
+# undef DEBUG_X
 #endif
 
 #if DEBUG_LEVEL
@@ -3369,6 +3369,18 @@
     wm_hint.initial_state = ISSET_OPTION(r, Opt_iconic) ? IconicState
 			    : NormalState;
     wm_hint.window_group = r->TermWin.parent;
+
+    /* window icon hint */
+    if( r->h->rs[Rs_appIcon] ) {
+        XpmReadFileToPixmap(r->Xdisplay, r->TermWin.parent, r->h->rs[Rs_appIcon],
+            &r->h->appIcon, &r->h->appIconMask,0);
+    }
+    if( r->h->appIcon != None &&  r->h->appIconMask != None ) {
+        wm_hint.icon_pixmap = r->h->appIcon;
+        wm_hint.icon_mask = r->h->appIconMask;
+        wm_hint.flags |= IconPixmapHint | IconMaskHint;
+    }
+    
     /* class hints */
     class_hint.res_name = (char*) r->h->rs[Rs_name];
     class_hint.res_class = (char*) APL_CLASS;
