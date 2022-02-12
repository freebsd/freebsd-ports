https://github.com/Plagman/gamescope/issues/410

--- src/vblankmanager.cpp.orig	2022-02-12 18:24:12 UTC
+++ src/vblankmanager.cpp
@@ -282,7 +282,7 @@ void fpslimitThreadRun( void )
 				// Don't roll back before current vblank
 				// based on varying draw time otherwise we can become divergent
 				// if these value change how we do not expect and get stuck in a feedback loop.
-				sleepyTime = std::max( sleepyTime, 0l );
+				sleepyTime = std::max<decltype(sleepyTime)>( sleepyTime, 0 );
 				sleepyTime -= g_uFPSLimiterRedZoneNS;
 				sleepyTime -= g_uVblankDrawBufferRedZoneNS;
 
