src/backends/x11/windowed/x11_windowed_qpainter_backend.cpp:47:71: error: use of undeclared identifier 'errno'
        qCWarning(KWIN_X11WINDOWED) << "shmget() failed:" << strerror(errno);
                                                                      ^
src/backends/x11/windowed/x11_windowed_qpainter_backend.cpp:54:70: error: use of undeclared identifier 'errno'
        qCWarning(KWIN_X11WINDOWED) << "shmat() failed:" << strerror(errno);
                                                                     ^

--- src/backends/x11/windowed/x11_windowed_qpainter_backend.cpp~	2023-02-09 12:15:33.000000000 +0000
+++ src/backends/x11/windowed/x11_windowed_qpainter_backend.cpp	2023-02-16 00:34:26.599527784 +0000
@@ -11,6 +11,7 @@
 #include "x11_windowed_logging.h"
 #include "x11_windowed_output.h"
 
+#include <cerrno>
 #include <string.h>
 #include <sys/shm.h>
 #include <xcb/present.h>
