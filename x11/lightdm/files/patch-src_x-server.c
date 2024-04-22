--- src/x-server.c.orig	2019-08-04 22:29:55 UTC
+++ src/x-server.c
@@ -152,13 +152,60 @@ x_server_connect_session (DisplayServer *display_serve
         g_autofree gchar *tty_text = NULL;
         g_autofree gchar *vt_text = NULL;
 
+#ifdef __FreeBSD__
+        char vty_num32[6];
+        int num;
+        const int base = 32;
+        size_t offset = 0;
+
+        num = vt - 1;
+
+        if (num == 0) {
+            vty_num32[offset++] = '0';
+            vty_num32[offset] = '\0';
+        } else {
+            for (int remaning = num; remaning > 0; remaning /= base, offset++) {
+                if (offset + 1 >= 6) {
+                    g_error ("tty number buffer too small");
+                    goto error;
+                }
+
+                const int value = remaning % base;
+                if (value >= 10) {
+                    vty_num32[offset] = 'a' + value - 10;
+                } else {
+                    vty_num32[offset] = '0' + value;
+                }
+            }
+
+            for (size_t i = 0; i < offset / 2; i++) {
+                const size_t p1 = i;
+                const size_t p2 = offset - 1 - i;
+                const char tmp = vty_num32[p1];
+                vty_num32[p1] = vty_num32[p2];
+                vty_num32[p2] = tmp;
+            }
+
+            vty_num32[offset] = '\0';
+        }
+
+        tty_text = g_strdup_printf ("/dev/ttyv%s", vty_num32);
+#else
         tty_text = g_strdup_printf ("/dev/tty%d", vt);
+#endif
         session_set_tty (session, tty_text);
 
+#ifdef __FreeBSD__
+        vt_text = g_strdup_printf ("%d", num);
+#else
         vt_text = g_strdup_printf ("%d", vt);
+#endif
         session_set_env (session, "XDG_VTNR", vt_text);
     }
     else
+#ifdef __FreeBSD__
+error:
+#endif
         l_debug (session, "Not setting XDG_VTNR");
 
     session_set_env (session, "DISPLAY", x_server_get_address (X_SERVER (display_server)));
