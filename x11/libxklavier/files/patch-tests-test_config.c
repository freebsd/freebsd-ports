--- tests/test_config.c.orig	Fri Oct  1 21:52:02 2004
+++ tests/test_config.c	Tue Oct 12 18:46:32 2004
@@ -46,6 +46,7 @@
   const char* layouts = NULL;
   const char* options = NULL;
   int debugLevel = 0;
+  Display* dpy;
 
   while (1)
   {
@@ -89,7 +90,7 @@
     exit( 0 );
   }
 
-  Display* dpy = XOpenDisplay( NULL );
+  dpy = XOpenDisplay( NULL );
   if ( dpy == NULL )
   {
     fprintf( stderr, "Could not open display\n" );
