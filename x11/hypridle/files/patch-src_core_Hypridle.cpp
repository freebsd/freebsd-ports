https://github.com/hyprwm/hypridle/issues/68#issuecomment-2428697344

--- src/core/Hypridle.cpp.orig	2025-08-07 09:04:25 UTC
+++ src/core/Hypridle.cpp
@@ -180,6 +180,7 @@ void CHypridle::enterEventLoop() {
         }
     });

+    m_sEventLoopInternals.loopRequestMutex.try_lock();
     while (1) { // dbus events
         // wait for being awakened
         m_sEventLoopInternals.loopRequestMutex.unlock(); // unlock, we are ready to take events
