--- glfw/wl_window.c.orig	1979-11-29 21:00:00 UTC
+++ glfw/wl_window.c
@@ -679,6 +679,12 @@ xdgToplevelHandleConfigure(void* data,
 #ifdef XDG_TOPLEVEL_STATE_SUSPENDED_SINCE_VERSION
             C(TOPLEVEL_STATE_SUSPENDED);
 #endif
+#ifdef XDG_TOPLEVEL_STATE_CONSTRAINED_LEFT_SINCE_VERSION
+            C(TOPLEVEL_STATE_CONSTRAINED_LEFT);
+            C(TOPLEVEL_STATE_CONSTRAINED_RIGHT);
+            C(TOPLEVEL_STATE_CONSTRAINED_TOP);
+            C(TOPLEVEL_STATE_CONSTRAINED_BOTTOM);
+#endif
 #undef C
         }
     }
