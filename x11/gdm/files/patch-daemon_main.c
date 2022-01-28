--- daemon/main.c.orig	2022-01-12 14:15:56 UTC
+++ daemon/main.c
@@ -289,6 +289,7 @@ is_debug_set (void)
         return debug;
 }
 
+#ifdef HAVE_SIGWAITINFO
 /* SIGUSR1 is used by the X server to tell us that we're ready, so
  * block it. We'll unblock it in the worker thread in gdm-server.c
  */
@@ -301,6 +302,7 @@ block_sigusr1 (void)
         sigaddset (&mask, SIGUSR1);
         sigprocmask (SIG_BLOCK, &mask, NULL);
 }
+#endif
 
 int
 main (int    argc,
@@ -321,7 +323,9 @@ main (int    argc,
                 { NULL }
         };
 
+#ifdef HAVE_SIGWAITINFO
         block_sigusr1 ();
+#endif
 
         bindtextdomain (GETTEXT_PACKAGE, GNOMELOCALEDIR);
         textdomain (GETTEXT_PACKAGE);
