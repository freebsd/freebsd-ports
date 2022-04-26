--- daemon/main.c.orig	2022-03-21 18:12:40 UTC
+++ daemon/main.c
@@ -281,6 +281,7 @@ is_debug_set (void)
         return debug;
 }
 
+#ifdef HAVE_SIGWAITINFO
 /* SIGUSR1 is used by the X server to tell us that we're ready, so
  * block it. We'll unblock it in the worker thread in gdm-server.c
  */
@@ -293,6 +294,7 @@ block_sigusr1 (void)
         sigaddset (&mask, SIGUSR1);
         sigprocmask (SIG_BLOCK, &mask, NULL);
 }
+#endif
 
 int
 main (int    argc,
@@ -313,7 +315,9 @@ main (int    argc,
                 { NULL }
         };
 
+#ifdef HAVE_SIGWAITINFO
         block_sigusr1 ();
+#endif
 
         bindtextdomain (GETTEXT_PACKAGE, GNOMELOCALEDIR);
         textdomain (GETTEXT_PACKAGE);
