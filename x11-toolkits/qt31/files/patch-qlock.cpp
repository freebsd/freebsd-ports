--- src/kernel/qlock.cpp.orig	Mon Dec  9 04:40:45 2002
+++ src/kernel/qlock.cpp	Sun Dec 29 05:31:54 2002
@@ -41,6 +41,7 @@
 #include <sys/file.h>
 #else
 #include <sys/types.h>
+#include <sys/ipc.h>
 #include <sys/sem.h>
 #if defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED) \
     || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD) || defined(Q_OS_BSDI)
