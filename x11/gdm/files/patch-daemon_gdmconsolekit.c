--- daemon/gdmconsolekit.c.orig	2007-08-30 22:57:18.000000000 -0400
+++ daemon/gdmconsolekit.c	2007-08-30 22:57:35.000000000 -0400
@@ -457,7 +457,7 @@ open_ck_session (struct passwd *pwent,
 		char *device;
 
 		/* FIXME: how does xorg construct this */
-		device = g_strdup_printf ("/dev/tty%d", d->vt);
+		device = g_strdup_printf ("/dev/ttyv%d", d->vt - 1);
 		add_param_string (&iter_struct, "x11-display-device", device);
 		g_free (device);
 	}
