--- kio/global.cpp.orig	Mon Sep 18 07:24:44 2000
+++ kio/global.cpp	Thu Nov  2 11:37:24 2000
@@ -28,6 +28,12 @@
 #include <string.h>
 #include <unistd.h>
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <sys/ucred.h>
+#include <sys/mount.h>
+#endif
+
 #ifdef HAVE_FSTAB_H
 #include <fstab.h>
 #endif
@@ -423,6 +429,30 @@
 
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
@@ -467,6 +497,7 @@
 
     ENDMNTENT(mtab);
     //kdDebug( 7007 ) << "Returning result " << result << endl;
+#endif
     return result;
 }
 

