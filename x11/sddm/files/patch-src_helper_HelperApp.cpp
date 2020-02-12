--- src/helper/HelperApp.cpp.orig	2019-03-13 09:22:35 UTC
+++ src/helper/HelperApp.cpp
@@ -35,7 +35,9 @@
 #include <sys/socket.h>
 #include <sys/time.h>
 
+#if defined(Q_OS_LINUX)
 #include <utmp.h>
+#endif
 #include <utmpx.h>
 #include <QByteArray>
 
@@ -302,12 +304,20 @@ namespace SDDM {
 
         // append to failed login database btmp
         if (!authSuccessful) {
+#if defined(Q_OS_FREEBSD)
+            pututxline(&entry);
+#else
             updwtmpx("/var/log/btmp", &entry);
+#endif
         }
 
         // append to wtmp
         else {
+#if defined(Q_OS_FREEBSD)
+            pututxline(&entry);
+#else
             updwtmpx("/var/log/wtmp", &entry);
+#endif
         }
     }
 
@@ -343,8 +353,12 @@ namespace SDDM {
             qWarning() << "Failed to write utmpx: " << strerror(errno);
         endutxent();
 
+#if defined(Q_OS_FREEBSD)
+        pututxline(&entry);
+#else
         // append to wtmp
         updwtmpx("/var/log/wtmp", &entry);
+#endif
     }
 }
 
