--- libxklavier/xklavier_config_xkb.c.orig	Fri Oct  1 22:04:54 2004
+++ libxklavier/xklavier_config_xkb.c	Tue Oct 12 18:44:59 2004
@@ -184,10 +184,11 @@
 
   if ( supportState == UNCHECKED )
   {
+    XkbRF_RulesPtr rulesPtr;
     XklDebug( 100, "!!! Checking multiple layouts support\n" );
     supportState = NON_SUPPORTED;
 #ifdef XKB_HEADERS_PRESENT
-    XkbRF_RulesPtr rulesPtr = _XklLoadRulesSet();
+    rulesPtr = _XklLoadRulesSet();
     if ( rulesPtr )
     {
       XkbRF_VarDefsRec varDefs;
