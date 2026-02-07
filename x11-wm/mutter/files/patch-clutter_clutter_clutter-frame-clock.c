--- clutter/clutter/clutter-frame-clock.c.orig	2023-10-31 18:35:00 UTC
+++ clutter/clutter/clutter-frame-clock.c
@@ -845,7 +845,7 @@ clutter_frame_clock_get_max_render_time_debug_info (Cl
   GString *string;
 
   string = g_string_new (NULL);
-  g_string_append_printf (string, "Max render time: %ld µs",
+  g_string_append_printf (string, "Max render time: %lld µs",
                           clutter_frame_clock_compute_max_render_time_us (frame_clock));
 
   if (frame_clock->got_measurements_last_frame)
@@ -857,9 +857,9 @@ clutter_frame_clock_get_max_render_time_debug_info (Cl
     MAX (frame_clock->longterm_max_update_duration_us,
          frame_clock->shortterm_max_update_duration_us);
 
-  g_string_append_printf (string, "\nVblank duration: %ld µs +",
+  g_string_append_printf (string, "\nVblank duration: %lld µs +",
                           frame_clock->vblank_duration_us);
-  g_string_append_printf (string, "\nUpdate duration: %ld µs +",
+  g_string_append_printf (string, "\nUpdate duration: %lld µs +",
                           max_update_duration_us);
   g_string_append_printf (string, "\nConstant: %d µs",
                           clutter_max_render_time_constant_us);
