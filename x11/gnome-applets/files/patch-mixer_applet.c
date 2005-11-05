--- mixer/applet.c.orig	Tue Oct  4 00:15:40 2005
+++ mixer/applet.c	Tue Oct  4 00:16:09 2005
@@ -953,7 +953,7 @@ gnome_volume_applet_adjust_volume (GstMi
 
   volumes = g_new (gint, track->num_channels);
   for (n = 0; n < track->num_channels; n++)
-    volumes[n] = lrintf (volume);
+    volumes[n] = (int)rint (volume);
   gst_mixer_set_volume (mixer, track, volumes);
   g_free (volumes);
 }
