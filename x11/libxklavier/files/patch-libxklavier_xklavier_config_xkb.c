--- libxklavier/xklavier_config_xkb.c.orig	Tue Jun 29 02:00:04 2004
+++ libxklavier/xklavier_config_xkb.c	Tue Jun 29 02:00:16 2004
@@ -173,9 +173,9 @@
 
   if ( supportState == UNCHECKED )
   {
+    XkbRF_RulesPtr rulesPtr = _XklLoadRulesSet();
     XklDebug( 100, "!!! Checking multiple layouts support\n" );
     supportState = NON_SUPPORTED;
-    XkbRF_RulesPtr rulesPtr = _XklLoadRulesSet();
     if ( rulesPtr )
     {
       XkbRF_VarDefsRec varDefs;
