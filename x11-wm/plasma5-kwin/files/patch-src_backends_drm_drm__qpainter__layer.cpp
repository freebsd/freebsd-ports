src/backends/drm/drm_qpainter_layer.cpp:54:79: error: use of undeclared identifier 'errno'
        qCWarning(KWIN_DRM, "Failed to create dumb framebuffer: %s", strerror(errno));
                                                                              ^
src/backends/drm/drm_qpainter_layer.cpp:66:87: error: use of undeclared identifier 'errno'
                qCWarning(KWIN_DRM, "Failed to create dumb framebuffer: %s", strerror(errno));
                                                                                      ^
src/backends/drm/drm_qpainter_layer.cpp:121:94: error: use of undeclared identifier 'errno'
        qCWarning(KWIN_DRM, "Failed to create dumb framebuffer for the cursor: %s", strerror(errno));
                                                                                             ^

--- src/backends/drm/drm_qpainter_layer.cpp.orig	2023-01-03 18:08:37 UTC
+++ src/backends/drm/drm_qpainter_layer.cpp
@@ -19,6 +19,7 @@
 #include "drm_qpainter_backend.h"
 #include "drm_virtual_output.h"
 
+#include <cerrno>
 #include <drm_fourcc.h>
 
 namespace KWin
