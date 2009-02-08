--- ../krunner/lock/lockprocess.cc	(revision 916963)
+++ ../krunner/lock/lockprocess.cc	(revision 916964)
@@ -1104,7 +1104,6 @@
         return; // no resuming with dialog visible or when not visible
     if( mSuspended && mHackProc.state() == QProcess::Running )
     {
-        XForceScreenSaver(QX11Info::display(), ScreenSaverReset );
         QPainter p( this );
         p.drawPixmap( 0, 0, mSavedScreen );
         p.end();
