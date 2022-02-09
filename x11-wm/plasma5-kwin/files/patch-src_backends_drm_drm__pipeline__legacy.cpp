--- src/backends/drm/drm_pipeline_legacy.cpp.orig	2022-02-09 06:05:36 UTC
+++ src/backends/drm/drm_pipeline_legacy.cpp
@@ -14,6 +14,8 @@
 #include "drm_object_connector.h"
 #include "logging.h"
 
+#include <errno.h>
+
 namespace KWin
 {
 
