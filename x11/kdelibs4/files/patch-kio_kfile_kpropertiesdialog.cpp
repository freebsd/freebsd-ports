--- ../kio/kfile/kpropertiesdialog.cpp.orig	2009-05-28 23:22:21.000000000 +0400
+++ ../kio/kfile/kpropertiesdialog.cpp	2009-05-29 23:35:59.000000000 +0400
@@ -1774,7 +1774,15 @@
 #else
     gid_t *groups = NULL;
 #endif
+#ifdef Q_OS_FREEBSD
+#include <osreldate.h>
+#endif
+#if defined(Q_OS_FREEBSD) && (__FreeBSD_version <= 800000) // Fixed in kern/114655
+    gid_t tmp_group;
+    if (getgrouplist(strUser, user->pw_gid, &tmp_group, &groupCount) < 0) {
+#else
     if (getgrouplist(strUser, user->pw_gid, NULL, &groupCount) < 0) {
+#endif
 #ifdef Q_OS_MAC
         groups = new int[groupCount];
 #else
