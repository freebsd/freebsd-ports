--- ksysguard~/gui/ksgrd/SensorManager.cc	2009-10-15 18:33:36.000000000 +0200
+++ ksysguard/gui/ksgrd/SensorManager.cc	2011-02-19 23:22:35.000000000 +0200
@@ -66,6 +66,7 @@
   mDict.insert( QLatin1String( "user" ), i18n( "User Load" ) );
   mDict.insert( QLatin1String( "sys" ), i18nc( "@item sensor description", "System Load" ) );
   mDict.insert( QLatin1String( "wait" ), i18n( "Waiting" ) );
+  mDict.insert( QLatin1String( "intr" ), i18n( "Interrupt Load" ) );
   mDict.insert( QLatin1String( "TotalLoad" ), i18n( "Total Load" ) );
   mDict.insert( QLatin1String( "mem" ), i18n( "Memory" ) );
   mDict.insert( QLatin1String( "physical" ), i18n( "Physical Memory" ) );
@@ -82,6 +83,7 @@
   mDict.insert( QLatin1String( "filepages" ), i18n( "File Pages" ) );
   mDict.insert( QLatin1String( "pscount" ), i18n( "Process Count" ) );
   mDict.insert( QLatin1String( "ps" ), i18n( "Process Controller" ) );
+  mDict.insert( QLatin1String( "lastpid" ), i18n( "Last Process ID" ) );
   mDict.insert( QLatin1String( "disk" ), i18n( "Disk Throughput" ) );
   mDict.insert( QLatin1String( "load" ), i18nc( "CPU Load", "Load" ) );
   mDict.insert( QLatin1String( "totalio" ), i18n( "Total Accesses" ) );
@@ -95,6 +97,8 @@
   mDict.insert( QLatin1String( "pageIn" ), i18n( "Pages In" ) );
   mDict.insert( QLatin1String( "pageOut" ), i18n( "Pages Out" ) );
   mDict.insert( QLatin1String( "context" ), i18n( "Context Switches" ) );
+  mDict.insert( QLatin1String( "trap" ), i18n( "Traps" ) );
+  mDict.insert( QLatin1String( "syscall" ), i18n( "System Calls" ) );
   mDict.insert( QLatin1String( "network" ), i18n( "Network" ) );
   mDict.insert( QLatin1String( "interfaces" ), i18n( "Interfaces" ) );
   mDict.insert( QLatin1String( "receiver" ), i18n( "Receiver" ) );
@@ -129,22 +133,30 @@
   mDict.insert( QLatin1String( "acpi" ), i18n( "ACPI" ) );
   mDict.insert( QLatin1String( "thermal_zone" ), i18n( "Thermal Zone" ) );
   mDict.insert( QLatin1String( "temperature" ), i18n( "Temperature" ) );
+  mDict.insert( QLatin1String( "AverageTemperature" ), i18n( "Average CPU Temperature" ) );
   mDict.insert( QLatin1String( "fan" ), i18n( "Fan" ) );
   mDict.insert( QLatin1String( "state" ), i18n( "State" ) );
   mDict.insert( QLatin1String( "battery" ), i18n( "Battery" ) );
+  mDict.insert( QLatin1String( "batterycapacity" ), i18n( "Battery Capacity" ) );
   mDict.insert( QLatin1String( "batterycharge" ), i18n( "Battery Charge" ) );
   mDict.insert( QLatin1String( "batteryusage" ), i18n( "Battery Usage" ) );
+  mDict.insert( QLatin1String( "batteryvoltage" ), i18n( "Battery Voltage" ) );
+  mDict.insert( QLatin1String( "batteryrate" ), i18n( "Battery Discharge Rate" ) );
   mDict.insert( QLatin1String( "remainingtime" ), i18n( "Remaining Time" ) );
   mDict.insert( QLatin1String( "interrupts" ), i18n( "Interrupts" ) );
   mDict.insert( QLatin1String( "loadavg1" ), i18n( "Load Average (1 min)" ) );
   mDict.insert( QLatin1String( "loadavg5" ), i18n( "Load Average (5 min)" ) );
   mDict.insert( QLatin1String( "loadavg15" ), i18n( "Load Average (15 min)" ) );
   mDict.insert( QLatin1String( "clock" ), i18n( "Clock Frequency" ) );
+  mDict.insert( QLatin1String( "AverageClock" ), i18n( "Average Clock Frequency" ) );
   mDict.insert( QLatin1String( "lmsensors" ), i18n( "Hardware Sensors" ) );
   mDict.insert( QLatin1String( "partitions" ), i18n( "Partition Usage" ) );
   mDict.insert( QLatin1String( "usedspace" ), i18n( "Used Space" ) );
   mDict.insert( QLatin1String( "freespace" ), i18n( "Free Space" ) );
   mDict.insert( QLatin1String( "filllevel" ), i18n( "Fill Level" ) );
+  mDict.insert( QLatin1String( "usedinode" ), i18n( "Used Inodes" ) );
+  mDict.insert( QLatin1String( "freeinode" ), i18n( "Free Inodes" ) );
+  mDict.insert( QLatin1String( "inodelevel" ), i18n( "Inode Level" ) );
   mDict.insert( QLatin1String( "system" ), i18n( "System" ) );
   mDict.insert( QLatin1String( "uptime" ), i18n( "Uptime" ) );
   mDict.insert( QLatin1String( "SoftRaid" ), i18n( "Linux Soft Raid (md)" ) );
@@ -167,16 +179,21 @@
   }
 
   for ( int i = 1; i < 6; i++) {
+    mDict.insert( QLatin1String( "batt" ) + QString::number( i ), i18n( "Battery %1", i ) );
     mDict.insert( QLatin1String( "fan" ) + QString::number( i ), i18n( "Fan %1", i ) );
     mDict.insert( QLatin1String( "temp" ) + QString::number( i ), i18n( "Temperature %1", i ) );
   }
 
   mDict.insert( QLatin1String( "int00" ), i18n( "Total" ) );
+  mDict.insert( QLatin1String( "softint" ), i18n( "Software Interrupts" ) );
+  mDict.insert( QLatin1String( "hardint" ), i18n( "Hardware Interrupts" ) );
 
   QString num;
   for ( int i = 1; i < 25; i++ ) {
     num.sprintf( "%.2d", i );
     mDict.insert( QLatin1String( "int" ) + num, ki18n( "Int %1" ).subs( i - 1, 3 ).toString() );
+    num.sprintf( "%.3d", i + 255);
+    mDict.insert( QLatin1String( "int" ) + num, ki18n( "Int %1" ).subs( i + 255, 4 ).toString() );
   }
 
   // TODO: translated descriptions not yet implemented.
@@ -186,6 +203,11 @@
   mUnits.insert( QLatin1String( "min" ), i18nc( "the unit minutes", "min" ) );
   mUnits.insert( QLatin1String( "MHz" ), i18nc( "the frequency unit", "MHz" ) );
   mUnits.insert( QLatin1String( "%" ), i18nc( "a percentage", "%" ) );
+  mUnits.insert( QLatin1String( "mA" ), i18nc( "the unit milliamperes", "mA" ) );
+  mUnits.insert( QLatin1String( "mAh" ), i18nc( "the unit milliampere hours", "mAh" ) );
+  mUnits.insert( QLatin1String( "mW" ), i18nc( "the unit milliwatts", "mW" ) );
+  mUnits.insert( QLatin1String( "mWh" ), i18nc( "the unit milliwatt hours", "mWh" ) );
+  mUnits.insert( QLatin1String( "mV" ), i18nc( "the unit millivolts", "mV" ) );
 
   mTypes.clear();
   mTypes.insert( QLatin1String( "integer" ), i18n( "Integer Value" ) );
