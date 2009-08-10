--- ./kcontrol/keyboard/kcmmisc.cpp.orig	2008-04-02 08:18:22.000000000 -0400
+++ ./kcontrol/keyboard/kcmmisc.cpp	2008-07-07 14:02:16.000000000 -0400
@@ -505,8 +505,10 @@
 
 
 	int numlockState = config.readEntry( "NumLock", 2 );
-	if( numlockState != 2 )
-		numlockx_change_numlock_state( numlockState == 0 );
+	if( numlockState == 2 )
+		numlockx_change_numlock_state( TRUE );
+	if( numlockState == 0 )
+		numlockx_change_numlock_state( FALSE );
 }
 
 
