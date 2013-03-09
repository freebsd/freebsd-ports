--- ./src/main.c.orig	2013-03-02 16:37:34.000000000 +0000
+++ ./src/main.c	2013-03-09 11:32:10.000000000 +0000
@@ -255,8 +255,10 @@
     xfce_textdomain(GETTEXT_PACKAGE, LOCALEDIR, "UTF-8");
     
 #if defined(ENABLE_FILE_ICONS) || defined(USE_DESKTOP_MENU)
+#if !GLIB_CHECK_VERSION (2, 32, 0)
     g_thread_init(NULL);
 #endif
+#endif
 #ifdef ENABLE_FILE_ICONS
     dbus_g_thread_init();
 #endif
