--- src/unix/fswatcher_kqueue.cpp.orig	2018-03-07 17:21:58 UTC
+++ src/unix/fswatcher_kqueue.cpp
@@ -20,8 +20,10 @@
 
 #ifdef wxHAS_KQUEUE
 
+#include <inttypes.h>
 #include <sys/types.h>
 #include <sys/event.h>
+#include <sys/param.h>
 
 #include "wx/dynarray.h"
 #include "wx/evtloop.h"
@@ -279,8 +281,12 @@ class wxFSWatcherImplKqueue : public wxFSWatcherImpl (
     {
         wxASSERT_MSG(e.udata, "Null user data associated with kevent!");
 
-        wxLogTrace(wxTRACE_FSWATCHER, "Event: ident=%d, filter=%d, flags=%u, "
-                   "fflags=%u, data=%d, user_data=%p",
+        wxLogTrace(wxTRACE_FSWATCHER, "Event: ident=%" PRIuPTR ", filter=%hd, flags=%hu, "
+#if __FreeBSD_version >= 1200033
+                   "fflags=%u, data=%" PRId64 ", user_data=%p",
+#else
+                   "fflags=%u, data=%" PRIdPTR ", user_data=%p",
+#endif
                    e.ident, e.filter, e.flags, e.fflags, e.data, e.udata);
 
         // for ease of use
