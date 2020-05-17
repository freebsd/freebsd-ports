--- src/unix/fswatcher_kqueue.cpp.orig	2020-05-04 14:49:11 UTC
+++ src/unix/fswatcher_kqueue.cpp
@@ -20,8 +20,10 @@
 
 #ifdef wxHAS_KQUEUE
 
+#include <inttypes.h>
 #include <sys/types.h>
 #include <sys/event.h>
+#include <sys/param.h>
 
 #include "wx/dynarray.h"
 #include "wx/evtloop.h"
@@ -295,9 +297,12 @@ class wxFSWatcherImplKqueue : public wxFSWatcherImpl (
         void* const udata = FromUdata(e.udata);
 
         wxASSERT_MSG(udata, "Null user data associated with kevent!");
-
-        wxLogTrace(wxTRACE_FSWATCHER, "Event: ident=%d, filter=%d, flags=%u, "
-                   "fflags=%u, data=%d, user_data=%p",
+        wxLogTrace(wxTRACE_FSWATCHER, "Event: ident=%" PRIuPTR ", filter=%hd, flags=%hu, "
+#if __FreeBSD_version >= 1200033
+                   "fflags=%u, data=%" PRId64 ", user_data=%p",
+#else
+                   "fflags=%u, data=%" PRIdPTR ", user_data=%p",
+#endif
                    e.ident, e.filter, e.flags, e.fflags, e.data, udata);
 
         // for ease of use
