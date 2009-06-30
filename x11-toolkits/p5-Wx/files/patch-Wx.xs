--- Wx.xs.orig	2009-04-20 22:17:27.000000000 +0200
+++ Wx.xs	2009-06-26 09:20:07.000000000 +0200
@@ -278,10 +278,7 @@ Load()
 
     if( wxPerlAppCreated || wxTopLevelWindows.GetCount() > 0 )
         return;
-#if defined(DEBUGGING) && !defined(PERL_USE_SAFE_PUTENV)
-    // avoid crash on exit in Fedora (and other DEBUGGING Perls)
     PL_use_safe_putenv = 1;
-#endif
 
     int argc = 0;
 #if wxUSE_UNICODE && WXPERL_W_VERSION_GE( 2, 5, 3 )
