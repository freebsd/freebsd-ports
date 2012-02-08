--- lib/libxview/notify/ntfyclient.c.orig	2012-02-03 16:47:24.025771621 -0800
+++ lib/libxview/notify/ntfyclient.c	2012-02-03 16:57:20.624935481 -0800
@@ -23,7 +23,15 @@
 /* Newsflash: As of libc-5.0.9, Linux has tsearch() & friends, so we define
  * HAVE_TSEARCH here.                  <martin-2.buck@student.uni-ulm.de>
  */
+
+/* XXX
+   XXX Previous version of the FreeBSD patch assumed FreeBSD had no
+   XXX tsearch() support or that it didn't work.
+   XXX
+   XXX */
+#ifdef __FreeBSD__
 #define HAVE_TSEARCH
+#endif
 
 #include <xview_private/ntfy.h>
 #include <xview_private/ndis.h>	/* For ndis_default_prioritizer */
@@ -103,7 +111,6 @@
            return (client);
        }
     }
-
     else 
 #endif
         /* Search entire list */
