--- kcontrol/konq/previews.cpp.orig	Sun Oct 26 11:46:25 2003
+++ kcontrol/konq/previews.cpp	Thu Jan 27 10:16:32 2005
@@ -153,6 +153,11 @@
 
     for ( ; it.current() ; ++it ) {
         QString protocol( it.current()->text() );
+        if ( ( protocol == "file" ) && ( !group.hasKey ( protocol ) ) ) 
+          // file should be enabled in case is not defined because if not so 
+          // than preview's lost when size is changed from default one 
+          it.current()->setOn( true ); 
+        else 
         it.current()->setOn( group.readBoolEntry( protocol, false ) );
     }
     // config key is in bytes (default value 1MB), numinput is in MB
