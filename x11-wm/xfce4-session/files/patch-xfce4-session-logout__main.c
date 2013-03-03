--- ./xfce4-session-logout/main.c.orig	2012-04-28 20:43:27.000000000 +0000
+++ ./xfce4-session-logout/main.c	2013-02-18 19:18:45.000000000 +0000
@@ -48,7 +48,7 @@
 gboolean opt_reboot = FALSE;
 gboolean opt_suspend = FALSE;
 gboolean opt_hibernate = FALSE;
-gboolean allow_save = FALSE;
+gboolean opt_fast = FALSE;
 gboolean opt_version = FALSE;
 
 enum
@@ -83,7 +83,7 @@
     N_("Hibernate without displaying the logout dialog"),
     NULL
   },
-  { "fast", 'f', G_OPTION_FLAG_IN_MAIN, G_OPTION_ARG_NONE, &allow_save,
+  { "fast", 'f', G_OPTION_FLAG_IN_MAIN, G_OPTION_ARG_NONE, &opt_fast,
     N_("Log out quickly; don't save the session"),
     NULL
   },
@@ -123,6 +123,7 @@
   gboolean         show_dialog;
   gboolean         result = FALSE;
   guint            shutdown_type;
+  gboolean         allow_save;
 
   xfce_textdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR, "UTF-8");
 
@@ -149,6 +150,9 @@
       return EXIT_FAILURE;
     }
 
+  /* save the session, unless fast is provided */
+  allow_save = !opt_fast;
+
   /* create messsage */
   proxy = dbus_g_proxy_new_for_name_owner (conn,
                                            "org.xfce.SessionManager",
