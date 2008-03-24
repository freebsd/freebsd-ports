--- applets/clock/clock-zonetable.c.orig	2008-01-20 13:32:13.000000000 -0500
+++ applets/clock/clock-zonetable.c	2008-01-20 13:35:34.000000000 -0500
@@ -124,7 +124,10 @@ clock_zonetable_new (gchar *zoneinfodir)
         priv = PRIVATE (this);
 
         priv->zonetab = g_build_filename (zoneinfodir, "zone.tab", NULL);
-        priv->iso3166 = g_build_filename (zoneinfodir, "iso3166.tab", NULL);
+        /*priv->iso3166 = g_build_filename (zoneinfodir, "iso3166.tab", NULL);*/
+	/* FreeBSD doesn't include iso3166.tab, so we install it especially
+	 * for this clock. */
+	priv->iso3166 = g_build_filename (DATADIR, "gnome-panel", "iso3166.tab", NULL);
 
 #ifdef CLOCK_TEXTDOMAIN
         /* this is used when clock is embedded in the gnome-panel
