--- tests/test_monitor.c.orig	Fri Oct  1 21:52:02 2004
+++ tests/test_monitor.c	Tue Oct 12 18:47:32 2004
@@ -42,6 +42,7 @@
   int c;
   int debugLevel = 0;
   XkbEvent ev;
+  Display* dpy;
 
   while (1)
   {
@@ -63,7 +64,7 @@
     }
   }
 
-  Display* dpy = XOpenDisplay( NULL );
+  dpy = XOpenDisplay( NULL );
   if ( dpy == NULL )
   {
     fprintf( stderr, "Could not open display\n" );
