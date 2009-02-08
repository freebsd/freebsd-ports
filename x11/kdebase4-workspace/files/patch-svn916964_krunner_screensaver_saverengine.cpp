--- ../krunner/screensaver/saverengine.cpp	(revision 916963)
+++ ../krunner/screensaver/saverengine.cpp	(revision 916964)
@@ -46,7 +46,11 @@
     // Save X screensaver parameters
     XGetScreenSaver(QX11Info::display(), &mXTimeout, &mXInterval,
                     &mXBlanking, &mXExposures);
-    // ... and disable it
+    // And disable it. The internal X screensaver is not used at all, but we use its
+    // internal idle timer (and it is also used by DPMS support in X). This timer must not
+    // be altered by this code, since e.g. resetting the counter after activating our
+    // screensaver would prevent DPMS from activating. We use the timer merely to detect
+    // user activity.
     XSetScreenSaver(QX11Info::display(), 0, mXInterval, mXBlanking, mXExposures);
 
     mState = Waiting;
@@ -87,7 +91,6 @@
 
 void SaverEngine::Lock()
 {
-    bool ok = true;
     if (mState == Waiting)
     {
         startLockProcess( ForceLock );
@@ -125,6 +128,7 @@
 
 void SaverEngine::SimulateUserActivity()
 {
+    XForceScreenSaver( QX11Info::display(), ScreenSaverReset );
     if ( mXAutoLock && mState == Waiting )
     {
         mXAutoLock->resetTrigger();
@@ -323,6 +327,8 @@
 //
 void SaverEngine::idleTimeout()
 {
+    if( mState != Waiting )
+        return; // already saving
     startLockProcess( DefaultLock );
 }
 
