--- kio/global.cpp	Sun Feb 18 10:27:06 2001
+++ kio/global.cpp.new	Thu Feb 22 23:47:34 2001
@@ -30,6 +30,12 @@
 #include <string.h>
 #include <unistd.h>
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <sys/ucred.h>
+#include <sys/mount.h>
+#endif
+
 #include "kio/global.h"
 #include "kio/job.h"
 
@@ -567,6 +573,30 @@
 
     /* Get the list of mounted file systems */
 
+#ifdef __FreeBSD__
+
+    QString result;
+    struct statfs *mounted;
+
+    int num_fs = getmntinfo(&mounted, MNT_NOWAIT);
+
+    for (int i=0;i<num_fs;i++) {
+
+      QCString device_name = mounted[i].f_mntfromname;
+
+      // If the path contains symlinks, get
+      // the real name
+      if (realpath(device_name, realpath_buffer) != 0)
+          // succes, use result from realpath
+         device_name = realpath_buffer;
+
+      if (realname == device_name) {
+        result = mounted[i].f_mntonname;
+	break;
+      }
+    }
+
+#else
     if ((mtab = SETMNTENT(MNTTAB, "r")) == 0) {
         perror("setmntent");
         return QString::null;
@@ -612,6 +642,7 @@
 #endif /* GET_MNTINFO */
 
     //kdDebug( 7007 ) << "Returning result " << result << endl;
+#endif
     return result;
 }
 
