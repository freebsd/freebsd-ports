--- libxklavier/xklavier_evt_xmm.c.orig	Tue Nov 30 02:18:31 2004
+++ libxklavier/xklavier_evt_xmm.c	Tue Nov 30 02:20:24 2004
@@ -13,15 +13,15 @@
 {
   if( _xklListenerType & XKLL_MANAGE_LAYOUTS )
   {
-    XklDebug( 200, "Processing the KeyPress event\n" );
     int currentShortcut = 0;
     const XmmSwitchOptionPtr sop = _XklXmmFindSwitchOption( kpe->keycode, 
-                                                            kpe->state,
-                                                            &currentShortcut );
+                                   kpe->state,
+                                   &currentShortcut );
+    XklDebug( 200, "Processing the KeyPress event\n" );
     if( sop != NULL )
     {
-      XklDebug( 150, "It is THE shortcut\n" );
       XklState state;
+      XklDebug( 150, "It is THE shortcut\n" );
       _XklXmmGetRealState( &state );
       if( state.group != -1 )
       {
