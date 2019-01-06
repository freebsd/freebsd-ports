https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=231425

In file included from ../sway/ipc-json.c:7:
In file included from ../include/sway/ipc-json.h:5:
In file included from ../include/sway/input/input-manager.h:6:
In file included from ../include/sway/server.h:9:
In file included from /usr/local/include/wlr/types/wlr_data_device.h:13:
/usr/local/include/wlr/types/wlr_seat.h:197:18: error: field has incomplete type 'struct timespec'
        struct timespec last_event;
                        ^
/usr/local/include/wlr/types/wlr_output.h:123:9: note: forward declaration of 'struct timespec'
        struct timespec *when;
               ^

--- include/wlr/types/wlr_seat.h.orig	2019-01-04 15:02:33 UTC
+++ include/wlr/types/wlr_seat.h
@@ -10,6 +10,9 @@
 #define WLR_TYPES_WLR_SEAT_H
 
 #include <time.h>
+#if defined(_C11_SOURCE) && defined(__FreeBSD__) && __FreeBSD__ < 12
+#include <sys/_timespec.h>
+#endif
 #include <wayland-server.h>
 #include <wlr/types/wlr_input_device.h>
 #include <wlr/types/wlr_keyboard.h>
