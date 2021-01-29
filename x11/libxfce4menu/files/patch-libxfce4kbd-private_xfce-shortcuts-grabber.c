--- libxfce4kbd-private/xfce-shortcuts-grabber.c.orig	2020-11-23 10:16:17 UTC
+++ libxfce4kbd-private/xfce-shortcuts-grabber.c
@@ -22,6 +22,8 @@
 #include <config.h>
 #endif
 
+#include <sys/param.h>
+
 #include <glib.h>
 #include <glib-object.h>
 
@@ -180,6 +182,9 @@ xfce_shortcuts_grabber_keys_changed (GdkKeymap        
 
   TRACE ("Keys changed, regrabbing");
 
+#ifdef __FreeBSD__
+  xfce_shortcuts_grabber_ungrab_all (grabber);
+#endif
   xfce_shortcuts_grabber_grab_all (grabber);
 }
 
