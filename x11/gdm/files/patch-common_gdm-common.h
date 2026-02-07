--- common/gdm-common.h.orig	2023-09-14 15:27:04 UTC
+++ common/gdm-common.h
@@ -29,6 +29,17 @@
 
 #define REGISTER_SESSION_TIMEOUT 10
 
+#if defined(WITH_CONSOLE_KIT)
+#define CK_NAME              "org.freedesktop.ConsoleKit"
+#define CK_PATH              "/org/freedesktop/ConsoleKit"
+#define CK_INTERFACE         "org.freedesktop.ConsoleKit"
+
+#define CK_MANAGER_PATH      "/org/freedesktop/ConsoleKit/Manager"
+#define CK_MANAGER_INTERFACE "org.freedesktop.ConsoleKit.Manager"
+#define CK_SEAT_INTERFACE    "org.freedesktop.ConsoleKit.Seat"
+#define CK_SESSION_INTERFACE "org.freedesktop.ConsoleKit.Session"
+#endif
+
 #define        VE_IGNORE_EINTR(expr) \
         do {                         \
                 errno = 0;           \
