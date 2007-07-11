--- konsole/konsole/main.cpp	2007/03/13 12:29:16	642131
+++ konsole/konsole/main.cpp	2007/05/29 14:32:54	669488
@@ -46,18 +46,15 @@
 
 #include "konsole.h"
 
-// COMPOSITE disabled by default because the QApplication constructor
-// needed to enable the ARGB32 visual has undesired side effects.
-//#if 0
 #if defined(Q_WS_X11) && defined(HAVE_XRENDER) && QT_VERSION >= 0x030300
 #define COMPOSITE
 #endif
-//#endif
 
 #ifdef COMPOSITE
 # include <X11/Xlib.h>
 # include <X11/extensions/Xrender.h>
 # include <fixx11h.h>
+# include <dlfcn.h>
 #endif
 
 static const char description[] =
@@ -255,47 +252,62 @@
   if( qtargs->isSet("font") )
       kdWarning() << "The Qt option -fn, --font has no effect." << endl;
 
+  KApplication* a = NULL;
 #ifdef COMPOSITE
-  char *display = 0;
-  if ( qtargs->isSet("display"))
-    display = qtargs->getOption( "display" ).data();
-
-  Display *dpy = XOpenDisplay( display );
-  if ( !dpy ) {
-    kdError() << "cannot connect to X server " << display << endl;
-    exit( 1 );
-  }
-
-  int screen = DefaultScreen( dpy );
-  Colormap colormap = 0;
-  Visual *visual = 0;
-  int event_base, error_base;
-
-  if ( args->isSet("real-transparency") && XRenderQueryExtension( dpy, &event_base, &error_base ) )
-  {
-    int nvi;
-    XVisualInfo templ;
-    templ.screen  = screen;
-    templ.depth   = 32;
-    templ.c_class = TrueColor;
-    XVisualInfo *xvi = XGetVisualInfo( dpy, VisualScreenMask | VisualDepthMask
-		  | VisualClassMask, &templ, &nvi );
-
-    for ( int i = 0; i < nvi; i++ ) {
-      XRenderPictFormat *format = XRenderFindVisualFormat( dpy, xvi[i].visual );
-      if ( format->type == PictTypeDirect && format->direct.alphaMask ) {
-        visual = xvi[i].visual;
-        colormap = XCreateColormap( dpy, RootWindow( dpy, screen ), visual, AllocNone );
-        kdDebug() << "found visual with alpha support" << endl;
-        argb_visual = true;
-        break;
+  if ( args->isSet("real-transparency")) {
+    char *display = 0;
+    if ( qtargs->isSet("display"))
+      display = qtargs->getOption( "display" ).data();
+
+    Display *dpy = XOpenDisplay( display );
+    if ( !dpy ) {
+      kdError() << "cannot connect to X server " << display << endl;
+      exit( 1 );
+    }
+
+    int screen = DefaultScreen( dpy );
+    Colormap colormap = 0;
+    Visual *visual = 0;
+    int event_base, error_base;
+
+    if ( XRenderQueryExtension( dpy, &event_base, &error_base ) ) {
+      int nvi;
+      XVisualInfo templ;
+      templ.screen  = screen;
+      templ.depth   = 32;
+      templ.c_class = TrueColor;
+      XVisualInfo *xvi = XGetVisualInfo( dpy, VisualScreenMask | VisualDepthMask
+		    | VisualClassMask, &templ, &nvi );
+
+      for ( int i = 0; i < nvi; i++ ) {
+        XRenderPictFormat *format = XRenderFindVisualFormat( dpy, xvi[i].visual );
+        if ( format->type == PictTypeDirect && format->direct.alphaMask ) {
+          visual = xvi[i].visual;
+          colormap = XCreateColormap( dpy, RootWindow( dpy, screen ), visual, AllocNone );
+          kdDebug() << "found visual with alpha support" << endl;
+          argb_visual = true;
+          break;
+        }
       }
     }
-  }
+    // The QApplication ctor used is normally intended for applications not using Qt
+    // as the primary toolkit (e.g. Motif apps also using Qt), with some slightly
+    // unpleasant side effects (e.g. #83974). This code checks if qt-copy patch #0078
+    // is applied, which allows turning this off.
+    bool* qt_no_foreign_hack = static_cast< bool* >( dlsym( RTLD_DEFAULT, "qt_no_foreign_hack" ));
+    if( qt_no_foreign_hack )
+        *qt_no_foreign_hack = true;
+    // else argb_visual = false ... ? *shrug*
 
-  KApplication a( dpy, Qt::HANDLE( visual ), Qt::HANDLE( colormap ) );
+    if( argb_visual )
+      a = new KApplication( dpy, Qt::HANDLE( visual ), Qt::HANDLE( colormap ) );
+    else
+      XCloseDisplay( dpy );
+  }
+  if( a == NULL )
+      a = new KApplication;
 #else
-  KApplication a;
+  KApplication* a = new KApplication;
 #endif
 
   QString dataPathBase = KStandardDirs::kde_default("data").append("konsole/");
@@ -351,7 +363,7 @@
   fixed_size = !args->isSet("resize");
 
   if (!full_script)
-	a.dcopClient()->setQtBridgeEnabled(false);
+	a->dcopClient()->setQtBridgeEnabled(false);
 
   QCString type = "";
 
@@ -467,13 +479,13 @@
   putenv((char*)"COLORTERM="); // to trigger mc's color detection
   KonsoleSessionManaged ksm;
 
-  if (a.isRestored() || !profile.isEmpty())
+  if (a->isRestored() || !profile.isEmpty())
   {
     if (!shell)
        shell = konsole_shell(eargs);
 
     if (profile.isEmpty())
-      sessionconfig = a.sessionConfig();
+      sessionconfig = a->sessionConfig();
     sessionconfig->setDesktopGroup();
     int n = 1;
 
@@ -629,7 +641,7 @@
     m->setAutoClose(auto_close);
   }
 
-  int ret = a.exec();
+  int ret = a->exec();
 
  //// Temporary code, waiting for Qt to do this properly
 
@@ -654,6 +666,8 @@
      delete w;
   }
   delete list;
+  
+  delete a;
 
   return ret;
 }
