--- src/X11InputMonitor.cc.orig	Sat Mar 22 14:53:57 2003
+++ src/X11InputMonitor.cc	Mon Jul 14 17:47:35 2003
@@ -39,6 +39,7 @@
 #if HAVE_UNISTD_H
 # include <unistd.h>
 #endif
+#include <sys/select.h>
 
 #include <X11/X.h>
 #include <X11/Xproto.h>
@@ -174,11 +175,13 @@
   TRACE_MSG("waiting");
   abort = true;
 
+#ifdef HAVE_XRECORD
   //FIXME:  stop_xrecord does not seem to work.
   if (use_xrecord)
     {
       monitor_thread->stop();
     }
+#endif
   //  wait_for_terminated_signal.wait();
   TRACE_EXIT();
 }
