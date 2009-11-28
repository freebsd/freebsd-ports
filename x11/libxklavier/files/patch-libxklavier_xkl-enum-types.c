--- libxklavier/xkl-enum-types.c.orig	2009-07-21 18:10:01.000000000 -0400
+++ libxklavier/xkl-enum-types.c	2009-07-21 18:10:04.000000000 -0400
@@ -21,9 +21,9 @@ xkl_engine_state_change_get_type (void)
 GType
 xkl_engine_features_get_type (void)
 {
-  static GType etype = 0;
-  if (etype == 0) {
-    static const GEnumValue values[] = {
+  static GType ftype = 0;
+  if (ftype == 0) {
+    static const GFlagsValue values[] = {
       { XKLF_CAN_TOGGLE_INDICATORS, "XKLF_CAN_TOGGLE_INDICATORS", "can-toggle-indicators" },
       { XKLF_CAN_OUTPUT_CONFIG_AS_ASCII, "XKLF_CAN_OUTPUT_CONFIG_AS_ASCII", "can-output-config-as-ascii" },
       { XKLF_CAN_OUTPUT_CONFIG_AS_BINARY, "XKLF_CAN_OUTPUT_CONFIG_AS_BINARY", "can-output-config-as-binary" },
@@ -32,9 +32,9 @@ xkl_engine_features_get_type (void)
       { XKLF_DEVICE_DISCOVERY, "XKLF_DEVICE_DISCOVERY", "device-discovery" },
       { 0, NULL, NULL }
     };
-    etype = g_enum_register_static ("XklEngineFeatures", values);
+    ftype = g_flags_register_static ("XklEngineFeatures", values);
   }
-  return etype;
+  return ftype;
 }
 GType
 xkl_engine_listen_modes_get_type (void)
