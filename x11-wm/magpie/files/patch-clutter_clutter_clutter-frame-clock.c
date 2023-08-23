--- clutter/clutter/clutter-frame-clock.c.orig	2023-02-13 18:12:26 UTC
+++ clutter/clutter/clutter-frame-clock.c
@@ -776,7 +776,7 @@ clutter_frame_clock_get_max_render_time_debug_info (Cl
   GString *string;
 
   string = g_string_new (NULL);
-  g_string_append_printf (string, "Max render time: %ld µs",
+  g_string_append_printf (string, "Max render time: %lld µs",
                           clutter_frame_clock_compute_max_render_time_us (frame_clock));
 
   if (frame_clock->got_measurements_last_frame)
@@ -797,13 +797,13 @@ clutter_frame_clock_get_max_render_time_debug_info (Cl
              frame_clock->swap_to_flip_us.values[i]);
     }
 
-  g_string_append_printf (string, "\nVblank duration: %ld µs +",
+  g_string_append_printf (string, "\nVblank duration: %lld µs +",
                           frame_clock->vblank_duration_us);
-  g_string_append_printf (string, "\nDispatch to swap: %ld µs +",
+  g_string_append_printf (string, "\nDispatch to swap: %lld µs +",
                           max_dispatch_to_swap_us);
-  g_string_append_printf (string, "\nmax(Swap to rendering done: %ld µs,",
+  g_string_append_printf (string, "\nmax(Swap to rendering done: %lld µs,",
                           max_swap_to_rendering_done_us);
-  g_string_append_printf (string, "\nSwap to flip: %ld µs) +",
+  g_string_append_printf (string, "\nSwap to flip: %lld µs) +",
                           max_swap_to_flip_us);
   g_string_append_printf (string, "\nConstant: %d µs",
                           clutter_max_render_time_constant_us);
