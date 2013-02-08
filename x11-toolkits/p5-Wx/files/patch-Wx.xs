--- Wx.xs.orig	2012-12-31 01:28:32.000000000 +0800
+++ Wx.xs	2012-12-31 01:29:02.000000000 +0800
@@ -325,10 +325,7 @@
 
     if( wxPerlAppCreated || wxTopLevelWindows.GetCount() > 0 )
         XSRETURN( true );
-#if defined(DEBUGGING) && !defined(PERL_USE_SAFE_PUTENV)
-    // avoid crash on exit in Fedora (and other DEBUGGING Perls)
     PL_use_safe_putenv = 1;
-#endif
 
     int argc = 0;
 #if wxUSE_UNICODE && WXPERL_W_VERSION_GE( 2, 5, 3 )
