$OpenBSD: patch-configure_ac,v 1.12 2017/04/17 13:17:07 ajacoutot Exp $

REVERT - Linux-PAM
From 714b6af29b916ac7da0cdab6f83460574ed49cf2 Mon Sep 17 00:00:00 2001
From: Ray Strode <rstrode@redhat.com>
Date: Mon, 15 Aug 2016 13:48:00 -0400
Subject: pam_gdm: add stub pam module

REVERT - OpenBSD does not have a systemd implementation (we need ConsoleKit)
From 1ac67f522f5690c27023d98096ca817f12f7eb88 Mon Sep 17 00:00:00 2001
From: Ray Strode <rstrode@redhat.com>
Date: Fri, 12 Jun 2015 13:28:01 -0400
Subject: drop consolekit support

https://bugzilla.gnome.org/show_bug.cgi?id=722482

--- configure.ac.orig	2017-10-30 16:21:11.000000000 +0100
+++ configure.ac	2018-01-14 13:01:16.646216000 +0100
@@ -232,12 +232,6 @@ AM_CONDITIONAL(ENABLE_EXHERBO_PAM_CONFIG, test x$with_
 AM_CONDITIONAL(ENABLE_LFS_PAM_CONFIG, test x$with_default_pam_config = xlfs)
 AM_CONDITIONAL(ENABLE_ARCH_PAM_CONFIG, test x$with_default_pam_config = xarch)
 
-AC_CHECK_HEADERS([security/pam_modules.h security/pam_modutil.h security/pam_ext.h],
-                 [have_pam=yes],
-                 [if test "x$have_pam" = xyes ; then
-                        AC_MSG_ERROR([PAM development files not found.])
-                 fi])
-
 AC_ARG_ENABLE(console-helper,
 	      AS_HELP_STRING([--enable-console-helper],
                              [Enable PAM console helper @<:@default=auto@:>@]),,
@@ -263,7 +257,15 @@ AC_ARG_WITH(tcp-wrappers,
                            [Use TCP Wrappers @<:@default=auto@:>@]),,
             with_tcp_wrappers=auto)
 
+AC_ARG_WITH(console-kit,
+            AS_HELP_STRING([--with-console-kit],
+                           [Add ConsoleKit support @<:@default=auto@:>@]),,
+            with_console_kit=no)
 
+AC_ARG_WITH(systemd,
+            AS_HELP_STRING([--with-systemd],
+                           [Add systemd support @<:@default=auto@:>@]),
+            [with_systemd=$withval], [with_systemd=auto])
 AC_ARG_WITH([systemdsystemunitdir],
             AS_HELP_STRING([--with-systemdsystemunitdir=DIR],
                            [Directory for systemd service files]),
@@ -548,6 +550,8 @@ fi
 if test "x$supports_pam_extensions" = "xyes" ; then
 	AM_CONDITIONAL(SUPPORTS_PAM_EXTENSIONS, true)
 	AC_DEFINE(SUPPORTS_PAM_EXTENSIONS, 1, [Define if PAM supports GDMs custom extensions])
+else
+	AM_CONDITIONAL(SUPPORTS_PAM_EXTENSIONS, false)
 fi
 
 AC_CHECK_LIB(keyutils, keyctl_read, [
@@ -655,14 +659,8 @@ dnl --------------------------------------------------
 dnl - Check for utmp stuff
 dnl ---------------------------------------------------------------------------
 
-AC_CHECK_HEADERS(utmp.h utmpx.h libutil.h sys/param.h)
-AC_CHECK_FUNCS([getutxent updwtmpx updwtmp])
-AC_CHECK_LIB(util, login, [
-		   AC_DEFINE(HAVE_LOGIN, 1, [Define if have login])
-		       EXTRA_DAEMON_LIBS="$EXTRA_DAEMON_LIBS -lutil" ])
-AC_CHECK_LIB(util, logout, [
-		   AC_DEFINE(HAVE_LOGOUT, 1, [Define if have logout])
-		       EXTRA_DAEMON_LIBS="$EXTRA_DAEMON_LIBS -lutil" ])
+AC_CHECK_HEADERS(utmp.h utmpx.h util.h sys/param.h)
+AC_CHECK_FUNCS([getutxent getttyent updwtmpx updwtmp])
 AC_CHECK_LIB(util, logwtmp, [
 	  	   AC_DEFINE(HAVE_LOGWTMP, 1, [Define if have logwtmp])
 		       EXTRA_DAEMON_LIBS="$EXTRA_DAEMON_LIBS -lutil" ])
@@ -911,12 +909,42 @@ AC_SUBST(XINERAMA_LIBS)
 CPPFLAGS="$xinerama_save_cppflags"
 
 dnl ---------------------------------------------------------------------------
+dnl - Check for ConsoleKit support
+dnl ---------------------------------------------------------------------------
+
+use_console_kit=no
+if test "x$with_console_kit" != "xno" ; then
+	use_console_kit=yes
+	AC_DEFINE(WITH_CONSOLE_KIT, 1, [Define to enable ConsoleKit support])
+fi
+AM_CONDITIONAL(WITH_CONSOLE_KIT, test x$use_console_kit = xyes)
+AC_SUBST(WITH_CONSOLE_KIT)
+
+dnl ---------------------------------------------------------------------------
 dnl - Check for systemd support
 dnl ---------------------------------------------------------------------------
 
 PKG_CHECK_MODULES(SYSTEMD,
-                  [libsystemd])
+                  [libsystemd-login >= 186 libsystemd-daemon],
+                  [have_systemd=yes], [have_systemd=no])
 
+if test "x$with_systemd" = "xauto" ; then
+        if test x$have_systemd = xno ; then
+                use_systemd=no
+        else
+                use_systemd=yes
+        fi
+else
+        use_systemd="$with_systemd"
+fi
+
+if test "x$use_systemd" != "xno" ; then
+        if test "x$have_systemd" = "xno"; then
+                AC_MSG_ERROR([Systemd support explicitly required, but systemd not found])
+        fi
+
+        AC_DEFINE(WITH_SYSTEMD, 1, [Define to enable systemd support])
+fi
 AC_SUBST(SYSTEMD_CFLAGS)
 AC_SUBST(SYSTEMD_LIBS)
 
@@ -1111,6 +1139,14 @@ fi
 AC_SUBST(GDM_CUSTOM_CONF)
 AC_SUBST(GDM_OLD_CONF, '${gdmconfdir}/gdm.conf')
 
+AC_ARG_WITH(consolekit-directory,
+              [AC_HELP_STRING([--with-consolekit-directory],
+                              [Specify the directory of ck-get-x11-display-device @<:@default=libexecdir@:>@])],,
+                              [with_consolekit_directory="\${libexecdir}"])
+
+CONSOLEKIT_DIR=$with_consolekit_directory
+AC_SUBST(CONSOLEKIT_DIR)
+
 AC_ARG_WITH(gnome-settings-daemon-directory,
               [AC_HELP_STRING([--with-gnome-settings-daemon-directory],
                               [Specify the directory of gnome-settings-daemon used by the chooser @<:@default=libexecdir@:>@])],,
@@ -1601,6 +1637,7 @@ echo "
         dmconfdir:                ${dmconfdir}
         localstatedir:            ${localstatedir}
         datadir:                  ${datadir}
+	consolekit location:      ${with_consolekit_directory}
 	gnome-settings-daemon location: ${with_gnome_settings_daemon_directory}
 	gnome-session-check-accel location: ${with_check_accelerated_directory}
 	source code location:	  ${srcdir}
@@ -1631,6 +1668,8 @@ echo \
 "        Xinerama support:         ${XINERAMA_SUPPORT}
         XDMCP support:            ${XDMCP_SUPPORT}
         SELinux support:          ${use_selinux}
+        ConsoleKit support:       ${use_console_kit}
+        systemd support:          ${use_systemd}
         systemd unit dir:         ${with_systemdsystemunitdir}
         plymouth support:         ${use_plymouth}
         wayland support:          ${enable_wayland_support}
@@ -1639,3 +1678,4 @@ echo \
         Enable documentation:     ${enable_documentation}
         Install GDM's Xsession:   ${enable_gdm_xsession}
 "
+
