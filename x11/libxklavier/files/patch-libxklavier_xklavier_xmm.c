--- libxklavier/xklavier_xmm.c.orig	Tue Dec 13 00:58:22 2005
+++ libxklavier/xklavier_xmm.c	Tue Dec 13 00:58:47 2005
@@ -66,7 +66,8 @@
 XmmSwitchOptionPtr _XklXmmGetCurrentShortcut( void )
 {
   const char* optionName = _XklXmmGetCurrentShortcutOptionName();
-  XmmSwitchOptionPtr switchOption = allSwitchOptions;
+  XmmSwitchOptionPtr switchOption;
+  switchOption = allSwitchOptions;
   XklDebug( 150, "Configured switch option: [%s]\n", optionName );
   if( optionName == NULL )
     return NULL;
