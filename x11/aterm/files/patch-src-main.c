--- src/main.c.orig	Tue Aug 16 14:56:31 2005
+++ src/main.c		Tue Aug 16 14:58:05 2005
@@ -1037,12 +1037,17 @@
 	XConfigureEvent *xconf = &(ev->xconfigure);
 	
 	while( XCheckTypedWindowEvent( Xdisplay, TermWin.parent, ConfigureNotify, ev ) );
+
+#ifdef DEBUG_X
 	fprintf( stderr, "config_geom = %dx%d\n", xconf->width, xconf->height );
+#endif
     resize_window1(xconf->width, xconf->height);
 #if 1
 	XTranslateCoordinates (Xdisplay, TermWin.parent, Xroot, 0, 0, &root_x, &root_y, &wdumm);
 
+#ifdef DEBUG_X
 	fprintf( stderr, "root_geom = %dx%d%+d%+d, root_size = %dx%d\n", xconf->width, xconf->height, root_x, root_y, XdisplayWidth, XdisplayHeight ); 
+#endif
 	TermWin.root_x = root_x ; 
 	TermWin.root_y = root_y ; 
 	TermWin.root_width = xconf->width ; 
