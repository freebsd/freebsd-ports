--- kio/kioexec/main.cpp.orig	Sun Oct 23 18:39:26 2005
+++ kio/kioexec/main.cpp	Sun Oct 23 18:40:10 2005
@@ -124,8 +124,12 @@
     }
     args->clear();
 
-    if ( tempfiles )
-        slotRunApp(); // does not return
+    if ( tempfiles ) {
+        // #113991
+        QTimer::singleShot( 0, this, SLOT( slotRunApp() ) );
+        //slotRunApp(); // does not return
+        return;
+    }
 
     counter = 0;
     if ( counter == expectedCounter )
