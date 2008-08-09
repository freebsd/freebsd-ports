--- ../ksysguard/gui/ksgrd/SensorManager.cc.orig	2008-04-15 04:49:59.000000000 +0200
+++ ../ksysguard/gui/ksgrd/SensorManager.cc	2008-04-15 04:51:01.000000000 +0200
@@ -61,6 +61,7 @@
   mDict.insert( QLatin1String( "nice" ), i18n( "Nice Load" ) );
   mDict.insert( QLatin1String( "user" ), i18n( "User Load" ) );
   mDict.insert( QLatin1String( "sys" ), i18n( "System Load" ) );
+  mDict.insert( QLatin1String( "intr" ), i18n( "Interrupt Load" ) );
   mDict.insert( QLatin1String( "wait" ), i18n( "Waiting" ) );
   mDict.insert( QLatin1String( "TotalLoad" ), i18n( "Total Load" ) );
   mDict.insert( QLatin1String( "mem" ), i18n( "Memory" ) );
