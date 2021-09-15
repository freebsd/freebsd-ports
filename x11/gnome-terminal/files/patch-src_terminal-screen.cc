--- src/terminal-screen.cc.orig	2021-09-15 17:25:45 UTC
+++ src/terminal-screen.cc
@@ -2272,7 +2272,7 @@ terminal_screen_has_foreground_process (TerminalScreen
   if (sysctl (mib, G_N_ELEMENTS (mib), nullptr, &len, nullptr, 0) == -1)
       return TRUE;
 
-  data_buf = g_malloc0 (len);
+  data_buf = (char *) g_malloc0 (len);
   if (sysctl (mib, G_N_ELEMENTS (mib), data_buf, &len, nullptr, 0) == -1)
       return TRUE;
   data = data_buf;
