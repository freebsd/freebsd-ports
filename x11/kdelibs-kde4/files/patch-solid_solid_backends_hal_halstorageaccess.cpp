--- solid/solid/backends/hal/halstorageaccess.cpp.orig	2017-11-05 01:51:22 UTC
+++ solid/solid/backends/hal/halstorageaccess.cpp
@@ -38,6 +38,7 @@
 #include <stdlib.h>
 
 #ifdef Q_OS_FREEBSD
+#include <sys/param.h>  // For __FreeBSD_version
 #include <langinfo.h>
 #endif
 
@@ -399,11 +400,20 @@ bool StorageAccess::callHalVolumeMount()
 
 #ifdef Q_OS_FREEBSD
     char *cType;
-    if ( fstype=="vfat" && halOptions.contains("-L=")) {
-        if ( (cType = getenv("LC_ALL")) || (cType = getenv("LC_CTYPE")) || (cType = getenv("LANG")) )
+    if ( fstype=="vfat" ) {
+        if ( halOptions.contains("-L=") && ((cType = getenv("LC_ALL")) || (cType = getenv("LC_CTYPE")) || (cType = getenv("LANG"))) )
               options << "-L="+QString(cType);
+#if __FreeBSD_version < 1200033
+        // The "large" option was removed in src r319735.
+        if ( halOptions.contains("large") )
+              options << "large";
+#endif
+        if ( halOptions.contains("-m=") )
+              options << "-m=644";
+        if ( halOptions.contains("-M=") )
+              options << "-M=755";
     }
-    else if ( (fstype.startsWith(QLatin1String("ntfs")) || fstype=="iso9660" || fstype=="udf") && halOptions.contains("-C=") ) {
+    else if ( (fstype=="ntfs" || fstype=="iso9660" || fstype=="udf") && halOptions.contains("-C=") ) {
         if ((cType = getenv("LC_ALL")) || (cType = getenv("LC_CTYPE")) || (cType = getenv("LANG")) )
             options << "-C="+QString(nl_langinfo(CODESET));
     }
@@ -418,6 +428,7 @@ bool StorageAccess::callHalVolumeMount()
         if (halOptions.contains("flush"))
             options<<"flush";
     }
+#endif
     // pass our locale to the ntfs-3g driver so it can translate local characters
     else if ( halOptions.contains("locale=") ) {
         // have to obtain LC_CTYPE as returned by the `locale` command
@@ -427,7 +438,6 @@ bool StorageAccess::callHalVolumeMount()
             options << "locale="+QString(cType);
         }
     }
-#endif
 
     msg << "" << fstype << options;
 
