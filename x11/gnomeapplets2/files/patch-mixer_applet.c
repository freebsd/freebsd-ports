--- mixer/applet.c.orig	Mon Nov  7 09:53:52 2005
+++ mixer/applet.c	Mon Nov 28 01:16:50 2005
@@ -953,7 +953,7 @@ gnome_volume_applet_adjust_volume (GstMi
 
   volumes = g_new (gint, track->num_channels);
   for (n = 0; n < track->num_channels; n++)
-    volumes[n] = lrint (volume);
+    volumes[n] = (int) rint (volume);
   gst_mixer_set_volume (mixer, track, volumes);
   g_free (volumes);
 }
