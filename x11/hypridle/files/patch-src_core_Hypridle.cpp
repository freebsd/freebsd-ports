https://github.com/hyprwm/hypridle/issues/68#issuecomment-2428697344

--- src/core/Hypridle.cpp.orig	2026-07-26 14:44:59 UTC
+++ src/core/Hypridle.cpp
@@ -212,6 +212,7 @@ void CHypridle::enterEventLoop() {
         }
     });
 
+    m_sEventLoopInternals.loopRequestMutex.try_lock();
     while (1) { // dbus events
         // wait for being awakened
         m_sEventLoopInternals.loopRequestMutex.unlock(); // unlock, we are ready to take events
