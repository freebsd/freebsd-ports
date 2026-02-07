--- libwacom/libwacomint.h.orig	2020-06-25 22:38:10 UTC
+++ libwacom/libwacomint.h
@@ -135,6 +135,9 @@ WacomStylus* libwacom_stylus_unref(WacomStylus *stylus
 WacomMatch* libwacom_match_ref(WacomMatch *match);
 WacomMatch* libwacom_match_unref(WacomMatch *match);
 
+#define libwacom_error_set libwacom_internal_error_set
+#define libwacom_match_new libwacom_internal_match_new
+
 void libwacom_error_set(WacomError *error, enum WacomErrorCode code, const char *msg, ...);
 void libwacom_add_match(WacomDevice *device, WacomMatch *newmatch);
 WacomMatch* libwacom_match_new(const char *name, WacomBusType bus,
