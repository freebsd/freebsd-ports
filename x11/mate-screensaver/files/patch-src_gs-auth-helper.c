--- src/gs-auth-helper.c.orig	2021-12-31 23:57:08 UTC
+++ src/gs-auth-helper.c
@@ -51,9 +51,6 @@
 #include "gs-auth.h"
 #include "subprocs.h"
 
-#include "../helper/helper_proto.h"
-#define MAXLEN 1024
-
 static gboolean verbose_enabled = FALSE;
 
 GQuark
@@ -82,105 +79,85 @@ gs_auth_get_verbose (void)
 
 static gboolean
 ext_run (const char *user,
-         GSAuthMessageFunc func,
-         gpointer   data)
+         const char *typed_passwd,
+         gboolean    verbose)
 {
-        int pfd[2], r_pfd[2], status;
-        pid_t pid;
-        gboolean verbose = gs_auth_get_verbose ();
+	int   pfd[2], status;
+	pid_t pid;
 
-        if (pipe (pfd) < 0 || pipe (r_pfd) < 0)
-        {
-                return FALSE;
-        }
+	if (pipe (pfd) < 0)
+	{
+		return 0;
+	}
 
-        if (verbose)
-        {
-                g_message ("ext_run (%s, %s)",
-                           PASSWD_HELPER_PROGRAM, user);
-        }
+	if (verbose)
+	{
+		g_message ("ext_run (%s, %s)",
+		           PASSWD_HELPER_PROGRAM, user);
+	}
 
-        block_sigchld ();
+	block_sigchld ();
 
-        if ((pid = fork ()) < 0)
-        {
-                close (pfd [0]);
-                close (pfd [1]);
-                close (r_pfd [0]);
-                close (r_pfd [1]);
-                return FALSE;
-        }
+	if ((pid = fork ()) < 0)
+	{
+		close (pfd [0]);
+		close (pfd [1]);
+		return FALSE;
+	}
 
-        if (pid == 0)
-        {
-                close (pfd [1]);
-                close (r_pfd [0]);
-                if (pfd [0] != 0)
-                {
-                        dup2 (pfd [0], 0);
-                }
-                if (r_pfd [1] != 1)
-                {
-                        dup2 (r_pfd [1], 1);
-                }
+	if (pid == 0)
+	{
+		close (pfd [1]);
+		if (pfd [0] != 0)
+		{
+			dup2 (pfd [0], 0);
+		}
 
-                /* Helper is invoked as helper service-name [user] */
-                execlp (PASSWD_HELPER_PROGRAM, PASSWD_HELPER_PROGRAM, "mate-screensaver", user, NULL);
-                if (verbose)
-                {
-                        g_message ("%s: %s", PASSWD_HELPER_PROGRAM, g_strerror (errno));
-                }
+		/* Helper is invoked as helper service-name [user] */
+		execlp (PASSWD_HELPER_PROGRAM, PASSWD_HELPER_PROGRAM, "mate-screensaver", user, NULL);
+		if (verbose)
+		{
+			g_message ("%s: %s", PASSWD_HELPER_PROGRAM, g_strerror (errno));
+		}
 
-                exit (1);
-        }
+		exit (1);
+	}
 
-        close (pfd [0]);
-        close (r_pfd [1]);
+	close (pfd [0]);
 
-        gboolean ret = FALSE;
-        while (waitpid (pid, &status, WNOHANG) == 0)
-        {
-                int msg_type;
-                char buf[MAXLEN];
-                size_t msg_len = MAXLEN;
+	/* Write out password to helper process */
+	if (!typed_passwd)
+	{
+		typed_passwd = "";
+	}
+	write (pfd [1], typed_passwd, strlen (typed_passwd));
+	close (pfd [1]);
 
-                msg_type = read_prompt (r_pfd [0], buf, &msg_len);
-                if (0 == msg_type) continue;
-                if (msg_type < 0)
-                {
-                        g_message ("Error reading prompt (%d)", msg_type);
-                        ret = FALSE;
-                        goto exit;
-                }
+	while (waitpid (pid, &status, 0) < 0)
+	{
+		if (errno == EINTR)
+		{
+			continue;
+		}
 
-                char *input = NULL;
-                func (msg_type, buf, &input, data);
+		if (verbose)
+		{
+			g_message ("ext_run: waitpid failed: %s\n",
+			           g_strerror (errno));
+		}
 
-                unsigned int input_len = input ? strlen (input) : 0;
-                ssize_t wt;
+		unblock_sigchld ();
+		return FALSE;
+	}
 
-                wt = write_msg (pfd [1], input, input_len);
-                if (wt < 0)
-                {
-                        g_message ("Error writing prompt reply (%li)", wt);
-                        ret = FALSE;
-                        goto exit;
-                }
-        }
+	unblock_sigchld ();
 
-        close (pfd [1]);
-        close (r_pfd [0]);
-        unblock_sigchld ();
+	if (! WIFEXITED (status) || WEXITSTATUS (status) != 0)
+	{
+		return FALSE;
+	}
 
-        if (! WIFEXITED (status) || WEXITSTATUS (status) != 0)
-        {
-                ret = FALSE;
-        }
-        else
-                ret = TRUE;
-
-  exit:
-        return ret;
+	return TRUE;
 }
 
 gboolean
@@ -190,7 +167,28 @@ gs_auth_verify_user (const char       *username,
                      gpointer          data,
                      GError          **error)
 {
-        return ext_run (username, func, data);
+	gboolean       res = FALSE;
+	char          *password;
+
+	password = NULL;
+
+	/* ask for the password for user */
+	if (func != NULL)
+	{
+		func (GS_AUTH_MESSAGE_PROMPT_ECHO_OFF,
+		      "Password: ",
+		      &password,
+		      data);
+	}
+
+	if (password == NULL)
+	{
+		return FALSE;
+	}
+
+	res = ext_run (username, password, gs_auth_get_verbose ());
+
+	return res;
 }
 
 gboolean
