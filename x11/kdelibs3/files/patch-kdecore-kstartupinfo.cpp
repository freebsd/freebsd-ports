--- kdecore/kstartupinfo.cpp	2007/10/08 11:32:36	722993
+++ kdecore/kstartupinfo.cpp	2007/10/12 12:13:00	724472
@@ -545,7 +545,7 @@
 
 void KStartupInfo::setNewStartupId( QWidget* window, const QCString& startup_id )
     {
-    long activate = true;
+    bool activate = true;
     kapp->setStartupId( startup_id );
     if( window != NULL )
         {
@@ -937,7 +937,7 @@
 #ifdef Q_WS_X11
     extern Time qt_x_user_time;
 #else
-    long qt_x_user_time = 0;
+    unsigned long qt_x_user_time = 0;
 #endif
     QCString id = QString( "%1;%2;%3;%4_TIME%5" ).arg( hostname ).arg( tm.tv_sec )
         .arg( tm.tv_usec ).arg( getpid()).arg( qt_x_user_time ).utf8();
@@ -1078,7 +1078,9 @@
     if( pos >= 0 )
         {
         bool ok;
-        long time = d->id.mid( pos + 5 ).toLong( &ok );
+        unsigned long time = d->id.mid( pos + 5 ).toULong( &ok );
+        if( !ok && d->id[ pos + 5 ] == '-' ) // try if it's as a negative signed number perhaps
+            time = d->id.mid( pos + 5 ).toLong( &ok );
         if( ok )
             return time;
         }
@@ -1093,7 +1095,9 @@
         if( pos2 >= 0 )
             {
             bool ok;
-            long time = d->id.mid( pos2 + 1, pos1 - pos2 - 1 ).toLong( &ok );
+            unsigned long time = d->id.mid( pos2 + 1, pos1 - pos2 - 1 ).toULong( &ok );
+            if( !ok && d->id[ pos + 5 ] == '-' ) // try if it's as a negative signed number perhaps
+                time = d->id.mid( pos2 + 1, pos1 - pos2 - 1 ).toLong( &ok );
             if( ok )
                 return time;
             }
