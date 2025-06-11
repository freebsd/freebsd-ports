Based on https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=258042

--- src/core/meta-context-main.c.orig	2025-03-04 18:56:53 UTC
+++ src/core/meta-context-main.c
@@ -25,7 +25,7 @@
 #include <glib.h>
 #include <gio/gio.h>
 
-#ifdef HAVE_WAYLAND
+#if defined(HAVE_LIBSYSTEMD) && defined(HAVE_WAYLAND)
 #include <systemd/sd-login.h>
 #endif
 
@@ -348,8 +348,10 @@ meta_context_main_get_x11_display_policy (MetaContext 
 #ifdef HAVE_WAYLAND
       if (context_main->options.no_x11)
         return META_X11_DISPLAY_POLICY_DISABLED;
+#ifdef HAVE_LIBSYSTEMD
       else if (sd_pid_get_user_unit (0, &unit) < 0)
         return META_X11_DISPLAY_POLICY_MANDATORY;
+#endif
       else
         return META_X11_DISPLAY_POLICY_ON_DEMAND;
 #else /* HAVE_WAYLAND */
