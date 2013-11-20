--- src/gs-auth-helper.c.orig	2011-03-16 17:24:06.000000000 -0500
+++ src/gs-auth-helper.c	2011-03-16 17:23:55.000000000 -0500
@@ -0,0 +1,198 @@
+/* -*- Mode: C; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 8 -*-
+ *
+ * written by Olaf Kirch <okir@suse.de>
+ * xscreensaver, Copyright (c) 1993-2004 Jamie Zawinski <jwz@jwz.org>
+ *
+ * Permission to use, copy, modify, distribute, and sell this software and its
+ * documentation for any purpose is hereby granted without fee, provided that
+ * the above copyright notice appear in all copies and that both that
+ * copyright notice and this permission notice appear in supporting
+ * documentation.  No representations are made about the suitability of this
+ * software for any purpose.  It is provided "as is" without express or 
+ * implied warranty.
+ */
+
+/* The idea here is to be able to run gnome-screensaver-dialog without any setuid bits.
+ * Password verification happens through an external program that you feed
+ * your password to on stdin.  The external command is invoked with a user
+ * name argument.
+ *
+ * The external helper does whatever authentication is necessary.  Currently,
+ * SuSE uses "unix2_chkpwd", which is a variation of "unix_chkpwd" from the
+ * PAM distribution.
+ *
+ * Normally, the password helper should just authenticate the calling user
+ * (i.e. based on the caller's real uid).  This is in order to prevent
+ * brute-forcing passwords in a shadow environment.  A less restrictive
+ * approach would be to allow verifying other passwords as well, but always
+ * with a 2 second delay or so.  (Not sure what SuSE's "unix2_chkpwd"
+ * currently does.)
+ *                         -- Olaf Kirch <okir@suse.de>, 16-Dec-2003
+ */
+
+#include "config.h"
+
+#include <stdlib.h>
+#ifdef HAVE_UNISTD_H
+# include <unistd.h>
+#endif
+
+#include <stdio.h>
+#include <string.h>
+#include <sys/types.h>
+#include <pwd.h>
+#include <errno.h>
+#include <sys/wait.h>
+
+#include <glib.h>
+#include <glib/gstdio.h>
+
+#include "gs-auth.h"
+#include "subprocs.h"
+
+static gboolean verbose_enabled = FALSE;
+
+GQuark
+gs_auth_error_quark (void)
+{
+        static GQuark quark = 0;
+        if (! quark) {
+                quark = g_quark_from_static_string ("gs_auth_error");
+        }
+
+        return quark;
+}
+
+void
+gs_auth_set_verbose (gboolean enabled)
+{
+        verbose_enabled = enabled;
+}
+
+gboolean
+gs_auth_get_verbose (void)
+{
+        return verbose_enabled;
+}
+
+static gboolean
+ext_run (const char *user,
+         const char *typed_passwd,
+         gboolean    verbose)
+{
+        int   pfd[2], status;
+        pid_t pid;
+
+        if (pipe (pfd) < 0) {
+                return 0;
+        }
+
+        if (verbose) {
+                g_message ("ext_run (%s, %s)",
+                           PASSWD_HELPER_PROGRAM, user);
+        }
+
+        block_sigchld ();
+
+        if ((pid = fork ()) < 0) {
+                close (pfd [0]);
+                close (pfd [1]);
+                return FALSE;
+        }
+
+        if (pid == 0) {
+                close (pfd [1]);
+                if (pfd [0] != 0) {
+                        dup2 (pfd [0], 0);
+                }
+
+                /* Helper is invoked as helper service-name [user] */
+                execlp (PASSWD_HELPER_PROGRAM, PASSWD_HELPER_PROGRAM, "gnome-screensaver", user, NULL);
+                if (verbose) {
+                        g_message ("%s: %s", PASSWD_HELPER_PROGRAM, g_strerror (errno));
+                }
+
+                exit (1);
+        }
+
+        close (pfd [0]);
+
+        /* Write out password to helper process */
+        if (!typed_passwd) {
+                typed_passwd = "";
+        }
+        write (pfd [1], typed_passwd, strlen (typed_passwd));
+        close (pfd [1]);
+
+        while (waitpid (pid, &status, 0) < 0) {
+                if (errno == EINTR) {
+                        continue;
+                }
+
+                if (verbose) {
+                        g_message ("ext_run: waitpid failed: %s\n",
+                                   g_strerror (errno));
+                }
+
+                unblock_sigchld ();
+                return FALSE;
+        }
+
+        unblock_sigchld ();
+
+        if (! WIFEXITED (status) || WEXITSTATUS (status) != 0) {
+                return FALSE;
+        }
+
+        return TRUE;
+}
+
+gboolean
+gs_auth_verify_user (const char       *username,
+                     const char       *display,
+                     GSAuthMessageFunc func,
+                     gpointer          data,
+                     GError          **error)
+{
+        gboolean       res = FALSE;
+        char          *password;
+
+        password = NULL;
+
+        /* ask for the password for user */
+        if (func != NULL) {
+                func (GS_AUTH_MESSAGE_PROMPT_ECHO_OFF,
+                      "Password: ",
+                      &password,
+                      data);
+        }
+
+        if (password == NULL) {
+                return FALSE;
+        }
+
+        res = ext_run (username, password, gs_auth_get_verbose ());
+
+        return res;
+}
+
+gboolean
+gs_auth_init (void)
+{
+        return TRUE;
+}
+
+gboolean
+gs_auth_priv_init (void)
+{
+        /* Make sure the passwd helper exists */
+        if (g_access (PASSWD_HELPER_PROGRAM, X_OK) < 0) {
+                g_warning ("%s does not exist. "
+                           "password authentication via "
+                           "external helper will not work.",
+                           PASSWD_HELPER_PROGRAM);
+                return FALSE;
+        }
+
+        return TRUE;
+}
