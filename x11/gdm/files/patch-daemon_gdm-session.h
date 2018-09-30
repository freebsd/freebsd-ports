$OpenBSD: patch-daemon_gdm-session_h,v 1.4 2016/04/26 08:25:04 ajacoutot Exp $

REVERT - OpenBSD does not have a systemd implementation (we need ConsoleKit)
From a9cacb929470eb82582396984c61d5b611bfeb1a Mon Sep 17 00:00:00 2001
From: Ray Strode <rstrode@redhat.com>
Date: Fri, 12 Jun 2015 14:33:40 -0400
Subject: session: drop session-type property

--- daemon/gdm-session.h.orig	Tue Apr 19 07:00:04 2016
+++ daemon/gdm-session.h	Tue Apr 26 10:02:48 2016
@@ -180,6 +180,8 @@ void              gdm_session_answer_query            
                                                            const char *text);
 void              gdm_session_select_program              (GdmSession *session,
                                                            const char *command_line);
+void              gdm_session_select_session_type         (GdmSession *session,
+                                                           const char *session_type);
 void              gdm_session_select_session              (GdmSession *session,
                                                            const char *session_name);
 void              gdm_session_select_user                 (GdmSession *session,
