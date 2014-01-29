--- src/gs-fade.c.orig	2013-11-25 08:42:45.005944760 +0000
+++ src/gs-fade.c	2013-11-25 08:43:11.449942142 +0000
@@ -420,7 +420,7 @@
 
 #ifdef HAVE_XF86VMODE_GAMMA
 	if (g_getenv("LTSP_CLIENT")) {
-		return FADE_TYPE_NONE;  /* We're on an LTSP Client, bad idea to fade at all */
+		return;
 	}
 
         res = XF86VidModeQueryExtension (GDK_DISPLAY_XDISPLAY (gdk_display_get_default ()), &event, &error);
