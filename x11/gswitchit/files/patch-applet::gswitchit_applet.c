--- applet/gswitchit_applet.c.orig	Thu Oct 23 03:06:04 2003
+++ applet/gswitchit_applet.c	Thu Oct 23 03:08:53 2003
@@ -520,11 +520,12 @@
   unsigned i, nGroups;
   char *pname;
   BonoboUIComponent *popup;
+  GSList *layout;
   popup = panel_applet_get_popup_component( PANEL_APPLET( sia->applet ) );
   XklDebug( 160, "Registered group submenu\n" );
   nGroups = XklGetNumGroups(  );
   pname = ( char * ) sia->groupNames;
-  GSList *layout = sia->xkbConfig.layouts;
+  layout = sia->xkbConfig.layouts;
   for( i = 0; i < nGroups; i++ )
   {
     char verb[40];
