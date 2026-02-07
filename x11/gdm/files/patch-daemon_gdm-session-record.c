--- daemon/gdm-session-record.c.orig	2022-01-12 14:15:56 UTC
+++ daemon/gdm-session-record.c
@@ -27,12 +27,20 @@
 
 #if defined(HAVE_UTMPX_H)
 #include <utmpx.h>
+#define utmp utmpx
 #endif
 
 #if defined(HAVE_UTMP_H)
 #include <utmp.h>
+#include <util.h>
 #endif
 
+#if defined(HAVE_GETTTYENT)
+#include <fcntl.h> /* open(2) */
+#include <ttyent.h>
+static int fd = -1;
+#endif
+
 #include <glib.h>
 #include <glib/gi18n.h>
 #include <glib/gstdio.h>
@@ -43,6 +51,9 @@
 #define GDM_BAD_SESSION_RECORDS_FILE "/var/log/btmp"
 #endif
 
+static void write_utmp_login_manually (struct utmp *ut);
+static void write_utmp_logout_manually (char *);
+
 #if !defined(GDM_NEW_SESSION_RECORDS_FILE)
 #    if defined(WTMPX_FILE)
 #        define GDM_NEW_SESSION_RECORDS_FILE WTMPX_FILE
@@ -168,6 +179,84 @@ record_set_line (UTMP       *u,
         g_debug ("using ut_line %.*s", (int) sizeof (u->ut_line), u->ut_line);
 }
 
+static void
+write_utmp_login_manually (struct utmp *ut)
+{
+#if defined(HAVE_GETTTYENT) && defined(HAVE_UTMP_H)
+        UTMP ubuf;
+        int topslot = -1;
+
+        g_debug ("Adding new utmp record");
+
+        /*
+         * First, loop through /etc/ttys, if needed, to initialize the
+         * top of the tty slots, since gdm has no tty.
+         */
+        if (topslot < 0) {
+                topslot = 0;
+                while (getttyent () != (struct ttyent *) NULL)
+                        topslot++;
+        }
+        if ((topslot < 0) || ((fd < 0) &&
+            (fd = open (_PATH_UTMP, O_RDWR|O_CREAT, 0644)) < 0))
+                return;
+
+        /*
+         * Now find a slot that's not in use...
+         */
+        (void) lseek (fd, (off_t) (topslot * sizeof (struct utmp)), SEEK_SET);
+
+        while (1) {
+                if (read (fd, &ubuf, sizeof (struct utmp)) ==
+                    sizeof (struct utmp)) {
+                        if (!ubuf.ut_name[0]) {
+                                (void) lseek (fd, -(off_t) sizeof (struct utmp),
+                                    SEEK_CUR);
+                                break;
+                        }
+                        topslot++;
+                } else {
+                        (void) lseek (fd, (off_t) (topslot *
+                            sizeof (struct utmp)), SEEK_SET);
+                        break;
+                }
+        }
+
+        (void) write (fd, ut, sizeof (struct utmp));
+#endif
+}
+
+static void
+write_utmp_logout_manually (char *line)
+{
+#if defined(HAVE_GETTTYENT) && defined(HAVE_UTMP_H)
+        int rval = 1;
+        struct timeval tv;
+        UTMP ut;
+
+        g_debug ("Removing utmp record");
+
+        if (fd >= 0) {
+            (void) lseek (fd, 0, SEEK_SET);
+            while (read (fd, &ut, sizeof (struct utmp)) == sizeof (struct utmp)) {
+                    if (!ut.ut_name[0] ||
+                        strncmp (ut.ut_line, line, UT_LINESIZE))
+                            continue;
+                    bzero (ut.ut_name, UT_NAMESIZE);
+                    bzero (ut.ut_host, UT_HOSTSIZE);
+                    gettimeofday (&tv, NULL);
+                    ut.ut_time = tv.tv_sec;
+                    (void) lseek (fd, -(off_t) sizeof (struct utmp), SEEK_CUR);
+                    (void) write (fd, &ut, sizeof (struct utmp));
+                    rval = 0;
+            }
+        }
+
+        if (rval != 0)
+            g_debug ("Failed to remove utmp record");
+#endif
+}
+
 void
 gdm_session_record_login (GPid                  session_pid,
                           const char           *user_name,
@@ -214,8 +303,9 @@ gdm_session_record_login (GPid                  sessio
         setutxent();
         pututxline (&session_record);
         endutxent();
-#elif defined(HAVE_LOGIN)
-	login (&session_record);
+#else
+        if (strcmp (session_record.ut_name, "(unknown)") != 0)
+	    write_utmp_login_manually (&session_record);
 #endif
 }
 
@@ -259,8 +349,8 @@ gdm_session_record_logout (GPid                  sessi
         setutxent();
         pututxline (&session_record);
         endutxent();
-#elif defined(HAVE_LOGOUT)
-        logout (session_record.ut_line);
+#else
+        write_utmp_logout_manually (session_record.ut_line);
 #endif
 }
 
