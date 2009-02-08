--- ../krunner/screensaver/xautolock.cpp	(revision 916963)
+++ ../krunner/screensaver/xautolock.cpp	(revision 916964)
@@ -83,8 +83,10 @@
     mActive = false;
 
     mTimerId = startTimer( CHECK_INTERVAL );
+    // This is an internal clock timer (in seconds), used instead of querying system time.
+    // It is incremented manually, preventing from problems with clock jumps.
+    // In other words, this is the 'now' time and the reference point for other times here.
     mElapsed = 0;
-
 }
 
 //---------------------------------------------------------------------------
@@ -126,8 +128,6 @@
 {
     mActive = true;
     resetTrigger();
-    XSetScreenSaver(QX11Info::display(), mTimeout + 10, 100, PreferBlanking, DontAllowExposures); // We'll handle blanking
-    kDebug() << "XSetScreenSaver" << mTimeout + 10;
 }
 
 //---------------------------------------------------------------------------
@@ -138,8 +138,6 @@
 {
     mActive = false;
     resetTrigger();
-    XSetScreenSaver(QX11Info::display(), 0, 100, PreferBlanking, DontAllowExposures); // No blanking at all
-    kDebug() << "XSetScreenSaver 0";
 }
 
 //---------------------------------------------------------------------------
@@ -148,12 +146,15 @@
 //
 void XAutoLock::resetTrigger()
 {
+    // Time of the last user activity (used only when the internal XScreensaver
+    // idle counter is not available).
     mLastReset = mElapsed;
+    // Time when screensaver should be activated.
     mTrigger = mElapsed + mTimeout;
 #ifdef HAVE_XSCREENSAVER
     mLastIdle = 0;
 #endif
-    XForceScreenSaver( QX11Info::display(), ScreenSaverReset );
+    // Do not reset the internal X screensaver here (no XForceScreenSaver())
 }
 
 //---------------------------------------------------------------------------
@@ -205,6 +206,9 @@
     if (mMitInfo)
     {
         Display *d = QX11Info::display();
+        // Check user idle time. If it is smaller than before, it is either
+        // clock jump or user activity, so reset the trigger time. Checking whether
+        // there is user inactivity timeout is done below using mTrigger and mElapsed.
         XScreenSaverQueryInfo(d, DefaultRootWindow(d), mMitInfo);
         if (mLastIdle < mMitInfo->idle)
             mLastIdle = mMitInfo->idle;
@@ -218,12 +222,11 @@
 
     bool activate = false;
 
-    // kDebug() << now << mTrigger;
+    // This is the test whether to activate screensaver. If we have reached the time
+    // and for the whole timeout period there was no activity (which would change mTrigger
+    // again), activate.
     if (mElapsed >= mTrigger)
-    {
-        resetTrigger();
         activate = true;
-    }
 
 #ifdef HAVE_DPMS
     BOOL on;
@@ -237,6 +240,8 @@
     // that is always smaller than DPMS timeout (X bug I guess). So if DPMS
     // saving is active, simply always activate our saving too, otherwise
     // this could prevent locking from working.
+    // X.Org 7.4: With this version activating DPMS resets the screensaver idle timer,
+    // so keep this. It probably makes sense to always do this anyway.
     if(state == DPMSModeStandby || state == DPMSModeSuspend || state == DPMSModeOff)
         activate = true;
     // If we are DPMS-dependent and either DPMS is turned off completely or all
