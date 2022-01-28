--- common/gdm-common.h.orig	2022-01-12 14:15:56 UTC
+++ common/gdm-common.h
@@ -29,6 +29,50 @@
 
 #define REGISTER_SESSION_TIMEOUT 10
 
+#if defined(WITH_SYSTEMD)
+#define SEAT_ID              "seat0"
+#elif defined(WITH_CONSOLE_KIT)
+#define CK_NAME              "org.freedesktop.ConsoleKit"
+#define CK_PATH              "/org/freedesktop/ConsoleKit"
+#define CK_INTERFACE         "org.freedesktop.ConsoleKit"
+
+#define CK_MANAGER_PATH      "/org/freedesktop/ConsoleKit/Manager"
+#define CK_MANAGER_INTERFACE "org.freedesktop.ConsoleKit.Manager"
+#define CK_SEAT_INTERFACE    "org.freedesktop.ConsoleKit.Seat"
+#define CK_SESSION_INTERFACE "org.freedesktop.ConsoleKit.Session"
+#define SEAT_ID              "/org/freedesktop/ConsoleKit/Seat1"
+
+int
+sd_pid_get_session(pid_t pid, char **session);
+
+int
+sd_session_get_uid(const char *session,
+                   uid_t *uid);
+
+int
+sd_session_get_class(const char *session, char **class);
+
+int
+sd_session_get_seat(const char *session,
+                    char      **seat);
+
+int
+sd_seat_get_sessions(const char   *seat,
+                     char       ***sessions,
+                     uid_t       **uid,
+                     unsigned int *n_uids);
+
+int
+sd_session_get_state(const char *session, char **state);
+
+int
+sd_session_get_service(const char *session,
+                       char **service);
+
+int
+sd_seat_can_graphical(const char *seat);
+#endif
+
 #define        VE_IGNORE_EINTR(expr) \
         do {                         \
                 errno = 0;           \
