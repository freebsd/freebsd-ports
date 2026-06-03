--- lumina-desktop/src-screensaver/LScreenSaver.cpp.orig	2026-04-15 11:46:29 UTC
+++ lumina-desktop/src-screensaver/LScreenSaver.cpp
@@ -27,7 +27,7 @@ LScreenSaver::LScreenSaver() : QWidget(0,Qt::BypassWin
 	LOCKER->hide();
   SSRunning = SSLocked = updating = false;
   this->setObjectName("LSCREENSAVERBASE");
-  this->setStyleSheet("LScreenSaver#LSCREENSAVERBASE{ background: darkgrey; }");
+  this->setStyleSheet("LScreenSaver#LSCREENSAVERBASE{ background: black; }");
   this->setMouseTracking(true);
   connect(starttimer, SIGNAL(timeout()), this, SLOT(ShowScreenSaver()) );
   connect(locktimer, SIGNAL(timeout()), this, SLOT(LockScreen()) );
