$OpenBSD: patch-src_backends_x11_meta-seat-x11_c,v 1.3 2021/06/04 10:56:17 ajacoutot Exp $

Index: src/backends/x11/meta-seat-x11.c
--- src/backends/x11/meta-seat-x11.c.orig
+++ src/backends/x11/meta-seat-x11.c
@@ -17,8 +17,9 @@
  * Author: Carlos Garnacho <carlosg@gnome.org>
  */
 #include "config.h"
-
+#ifdef __linux__
 #include <linux/input-event-codes.h>
+#endif
 #include <X11/extensions/XInput2.h>
 #include <X11/extensions/XKB.h>
 
@@ -1733,7 +1734,7 @@ get_source_device_checked (MetaSeatX11   *seat,
 
   return source_device;
 }
-
+#ifdef __linux__
 static uint32_t
 evdev_button_code (uint32_t x_button)
 {
@@ -1762,7 +1763,7 @@ evdev_button_code (uint32_t x_button)
 
   return button;
 }
-
+#endif
 gboolean
 meta_seat_x11_translate_event (MetaSeatX11  *seat,
                                XEvent       *xevent,
@@ -2050,7 +2051,9 @@ meta_seat_x11_translate_event (MetaSeatX11  *seat,
             event->button.time = xev->time;
             translate_coords (stage_x11, xev->event_x, xev->event_y, &event->button.x, &event->button.y);
             event->button.button = xev->detail;
+#ifdef __linux__
             event->button.evdev_code = evdev_button_code (xev->detail);
+#endif
             meta_input_device_x11_translate_state (event,
                                                    &xev->mods,
                                                    &xev->buttons,
