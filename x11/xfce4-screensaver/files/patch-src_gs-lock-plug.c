From 5a6b01aaeb109ef419ab021972a4225618b277ce Mon Sep 17 00:00:00 2001
From: Guido Falsi <madpilot@freebsd.org>
Date: Sun, 16 Nov 2025 12:14:37 +0100
Subject: [PATCH] Use pgrep in place of pidof

This also simplifies function logic.

Fixes: #38
---
 src/gs-lock-plug.c | 16 ++++------------
 1 file changed, 4 insertions(+), 12 deletions(-)

diff --git a/src/gs-lock-plug.c b/src/gs-lock-plug.c
index d0806f64..fce7bf15 100644
--- src/gs-lock-plug.c
+++ src/gs-lock-plug.c
@@ -26,6 +26,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/utsname.h>
+#include <sys/wait.h>
 #include <time.h>
 #include <unistd.h>
 
@@ -179,20 +180,11 @@ toggle_infobar_visibility (GSLockPlug *plug) {
 
 static gboolean
 process_is_running (const char *name) {
-    int num_processes;
-    gchar *command = g_strdup_printf ("pidof %s | wc -l", name);
-    FILE *fp = popen (command, "r");
+    gchar *command = g_strdup_printf ("pgrep -a %s", name);
+    int rc = system (command);
     g_free (command);
 
-    if (fp == NULL)
-        return FALSE;
-
-    if (fscanf (fp, "%d", &num_processes) != 1)
-        num_processes = 0;
-
-    pclose (fp);
-
-    if (num_processes > 0) {
+    if (WIFEXITED (rc) && WEXITSTATUS (rc) == 0) {
         return TRUE;
     } else {
         return FALSE;
-- 
GitLab

