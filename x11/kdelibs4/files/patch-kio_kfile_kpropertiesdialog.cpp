--- ../kio/kfile/kpropertiesdialog.cpp.orig	2009-05-06 14:14:38.000000000 +0400
+++ ../kio/kfile/kpropertiesdialog.cpp	2009-05-30 00:46:08.000000000 +0400
@@ -1804,7 +1804,15 @@
 #else
     QVarLengthArray<gid_t> groups;
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
         groups.resize(groupCount);
         if (groups.data())
             getgrouplist(strUser, user->pw_gid, groups.data(), &groupCount);
