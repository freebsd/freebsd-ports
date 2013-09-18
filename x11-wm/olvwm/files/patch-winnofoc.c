--- winnofoc.c.orig	2013-09-17 21:38:07.492238885 -0700
+++ winnofoc.c	2013-09-17 22:06:01.202842480 -0700
@@ -239,7 +239,7 @@
         XEvent dummy;
 
 	if (FindModifierMask(event->xkey.keycode) != 0)
-		return;
+		return 0;
 
         XSync(dpy,0);
         /*
