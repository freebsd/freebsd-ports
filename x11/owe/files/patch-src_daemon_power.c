--- src/daemon/power.c.orig	2026-09-22 11:50:27 UTC
+++ src/daemon/power.c
@@ -3,8 +3,22 @@
 #include <time.h>
 #include <stdlib.h>
 #include <string.h>
+#ifdef HAVE_LIBSYSTEMD
 #include <systemd/sd-bus.h>
 #include <systemd/sd-login.h>
+#else
+/* basu provides the sd-bus API without the rest of libsystemd. */
+#include <basu/sd-bus.h>
+#endif
+
+#ifndef HAVE_SD_BUS_CLOSE_UNREF
+/* sd_bus_close_unref() is systemd >= 241 API that basu lacks. */
+static sd_bus *owe_sd_bus_close_unref(sd_bus *bus) {
+    if (bus) sd_bus_close(bus);
+    return sd_bus_unref(bus);
+}
+#define sd_bus_close_unref owe_sd_bus_close_unref
+#endif
 #include <unistd.h>
 #include "daemon.h"
 #include "log.h"
@@ -87,8 +101,10 @@ static void connect_system(struct owed_power *p) {
                         "org.freedesktop.login1.Manager", "PrepareForSleep", sleep_signal, p);
 
     char *sid = NULL;
+#ifdef HAVE_LIBSYSTEMD
     /* A systemd user service often has no session in its own cgroup. */
     if (sd_pid_get_session(getpid(), &sid) < 0) sd_uid_get_display(getuid(), &sid);
+#endif
     if (!sid && getenv("XDG_SESSION_ID")) sid = strdup(getenv("XDG_SESSION_ID"));
     sd_bus_message *reply = NULL;
     if (sid && sd_bus_call_method(p->system, "org.freedesktop.login1", "/org/freedesktop/login1",
