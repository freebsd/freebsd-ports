--- clients/olwm/winnofoc.c.orig	2005-03-28 06:39:46.000000000 -0800
+++ clients/olwm/winnofoc.c	2013-09-17 23:05:56.531520358 -0700
@@ -219,7 +219,7 @@
         XEvent dummy;
 
 	if (FindModifierMask(event->xkey.keycode) != 0)
-		return;
+		return 0;
 
         XSync(dpy,0);
         /*
