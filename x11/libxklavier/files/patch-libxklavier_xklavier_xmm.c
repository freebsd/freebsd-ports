--- libxklavier/xklavier_xmm.c.orig	Tue Nov 30 02:17:37 2004
+++ libxklavier/xklavier_xmm.c	Tue Nov 30 02:17:51 2004
@@ -66,10 +66,11 @@
 const XmmSwitchOptionPtr _XklXmmGetCurrentShortcut()
 {
   const char* optionName = _XklXmmGetCurrentShortcutOptionName();
+  XmmSwitchOptionPtr switchOption;
   XklDebug( 150, "Configured switch option: [%s]\n", optionName );
   if( optionName == NULL )
     return NULL;
-  XmmSwitchOptionPtr switchOption = allSwitchOptions;
+  switchOption = allSwitchOptions;
   while( switchOption->optionName != NULL )
   {
     if( !strcmp( switchOption->optionName, optionName ) )
