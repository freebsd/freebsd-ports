Drop after FreeBSD 11 EOL, other systems had timespec_get() for years.

../src/log.c:162:20: error: use of undeclared identifier 'TIME_UTC'
        timespec_get(&ts, TIME_UTC);
                          ^
log.c:(.text+0x1db): undefined reference to `timespec_get'

--- src/log.c.orig	2019-09-21 00:08:00 UTC
+++ src/log.c
@@ -159,7 +159,11 @@ attr_printf(4, 5) void log_printf(struct log *l, int l
 	}
 
 	struct timespec ts;
+#ifdef TIME_UTC
 	timespec_get(&ts, TIME_UTC);
+#else
+	clock_gettime(CLOCK_REALTIME, &ts);
+#endif
 	auto tm = localtime(&ts.tv_sec);
 	char time_buf[100];
 	strftime(time_buf, sizeof time_buf, "%x %T", tm);
