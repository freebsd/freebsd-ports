$OpenBSD: patch-common_gdm-common_h,v 1.2 2016/04/15 14:11:09 ajacoutot Exp $

REVERT - OpenBSD does not have a systemd implementation (we need ConsoleKit)
From 9be58c9ec9a3a411492a5182ac4b0d51fdc3a323 Mon Sep 17 00:00:00 2001
From: Ray Strode <rstrode@redhat.com>
Date: Fri, 12 Jun 2015 13:48:52 -0400
Subject: require logind support

--- common/gdm-common.h.orig	Thu Apr 14 07:27:26 2016
+++ common/gdm-common.h	Fri Apr 15 15:05:26 2016
@@ -31,6 +31,9 @@
                 expr;                \
         } while G_UNLIKELY (errno == EINTR);
 
+/* check if logind is running */
+#define LOGIND_RUNNING() (access("/run/systemd/seats/", F_OK) >= 0)
+
 GQuark gdm_common_error_quark (void);
 #define GDM_COMMON_ERROR gdm_common_error_quark()
 
