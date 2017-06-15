* More detailed Memory stats in the KSysGuard's Status Bar
*
* Make the the Status Bar elements reasonably proportional in size
*
--- ksysguard/gui/ksysguard.cpp.orig	2015-06-26 03:17:21 UTC
+++ ksysguard/gui/ksysguard.cpp
@@ -93,19 +93,21 @@ TopLevel::TopLevel()
   /* Create the status bar. It displays some information about the
    * number of processes and the memory consumption of the local
    * host. */
-  const int STATUSBAR_STRETCH=1;
-
   sbProcessCount = new QLabel();
-  statusBar()->addWidget( sbProcessCount, STATUSBAR_STRETCH );
+  sbProcessCount->setAlignment( Qt::AlignHCenter );
+  statusBar()->addWidget( sbProcessCount, 3 );      // 1 long label + 1 value = 3
 
   sbCpuStat = new QLabel();
-  statusBar()->addWidget( sbCpuStat, STATUSBAR_STRETCH );
+  sbCpuStat->setAlignment( Qt::AlignHCenter );
+  statusBar()->addWidget( sbCpuStat, 2 );           // 1 short label + 1 value = 2
 
   sbMemTotal = new QLabel();
-  statusBar()->addWidget( sbMemTotal, STATUSBAR_STRETCH );
+  sbMemTotal->setAlignment( Qt::AlignHCenter );
+  statusBar()->addWidget( sbMemTotal, 5 );          // 1 label + 4 values = 5
 
   sbSwapTotal = new QLabel();
-  statusBar()->addWidget( sbSwapTotal, STATUSBAR_STRETCH );
+  sbSwapTotal->setAlignment( Qt::AlignHCenter );
+  statusBar()->addWidget( sbSwapTotal, 3 );         // 1 label + 2 values = 3
 
   statusBar()->hide();
 
@@ -453,11 +455,7 @@ void TopLevel::answerReceived( int id, c
 
     case 4:
       mUsedApplication = answer.toLongLong();
-      //Use a multi-length string
-      s = i18nc( "Arguments are formatted byte sizes (used/total)", "Memory: %1 / %2" "\xc2\x9c" "Mem: %1 / %2" "\xc2\x9c" "Mem: %1" "\xc2\x9c" "%1",
-                 KGlobal::locale()->formatByteSize( mUsedApplication*1024),
-                 KGlobal::locale()->formatByteSize( (mFree+mUsedTotal)*1024 ) );
-      sbMemTotal->setText( s );
+      setMemInfo( mUsedApplication, mUsedTotal, mFree, unit );
       break;
 
     case 5:
@@ -477,6 +475,17 @@ void TopLevel::answerReceived( int id, c
   }
 }
 
+void TopLevel::setMemInfo(qlonglong usedapps, qlonglong usedtotal, qlonglong free, const QString & )
+{
+  QString msg;
+  msg = i18nc( "Arguments are formatted byte sizes (used/total)", "Memory: (K %4 + U %3) %1 / %2" "\xc2\x9c" "Memory: (U %3) %1 / %2" "\xc2\x9c" "Memory: %1 / %2" "\xc2\x9c" "Mem: %1 / %2" "\xc2\x9c" "Mem: %1" "\xc2\x9c" "%1",
+               KGlobal::locale()->formatByteSize( usedtotal*1024 ),
+               KGlobal::locale()->formatByteSize( (free+usedtotal)*1024 ),
+               KGlobal::locale()->formatByteSize( usedapps*1024 ),
+               KGlobal::locale()->formatByteSize( (usedtotal-usedapps)*1024 ) );
+  sbMemTotal->setText( msg );
+}
+
 void TopLevel::setSwapInfo( qlonglong used, qlonglong free, const QString & )
 {
   QString msg;
@@ -487,7 +496,6 @@ void TopLevel::setSwapInfo( qlonglong us
                  KGlobal::locale()->formatByteSize( used*1024 ),
                  KGlobal::locale()->formatByteSize( (free+used)*1024) );
   }
-
   sbSwapTotal->setText( msg );
 }
 
