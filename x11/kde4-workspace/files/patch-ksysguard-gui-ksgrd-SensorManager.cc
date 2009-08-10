--- ./ksysguard/gui/ksgrd/SensorManager.cc.orgi	2009-01-22 23:54:35.000000000 +0100
+++ ./ksysguard/gui/ksgrd/SensorManager.cc	2009-01-22 23:54:52.000000000 +0100
@@ -61,6 +61,7 @@
   mDict.insert( QLatin1String( "nice" ), i18n( "Nice Load" ) );
   mDict.insert( QLatin1String( "user" ), i18n( "User Load" ) );
   mDict.insert( QLatin1String( "sys" ), i18nc( "@item sensor description", "System Load" ) );
+  mDict.insert( QLatin1String( "intr" ), i18n( "Interrupt Load" ) );
   mDict.insert( QLatin1String( "wait" ), i18n( "Waiting" ) );
   mDict.insert( QLatin1String( "TotalLoad" ), i18n( "Total Load" ) );
   mDict.insert( QLatin1String( "mem" ), i18n( "Memory" ) );
