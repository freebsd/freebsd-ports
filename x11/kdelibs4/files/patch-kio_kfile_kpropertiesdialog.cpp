--- ../kio/kfile/kpropertiesdialog.cpp.orig	2009-03-26 17:44:17.000000000 +0300
+++ ../kio/kfile/kpropertiesdialog.cpp	2009-04-03 00:02:27.000000000 +0400
@@ -1770,7 +1770,15 @@
     // pick the groups to which the user belongs
     int groupCount = 0;
     gid_t *groups = NULL;
+#ifdef Q_OS_FREEBSD
+#include <osreldate.h>
+#endif
+#if defined(Q_OS_FREEBSD) && (__FreeBSD_version <= 800000) // Fixed in kern/114655
+    gid_t tmp_group;
+    if (getgrouplist(strUser, user->pw_gid, &tmp_group, &groupCount) < 0) {
+#else
     if (getgrouplist(strUser, user->pw_gid, NULL, &groupCount) < 0) {
+#endif
         groups = new gid_t[groupCount];
         if (groups) {
             getgrouplist(strUser, user->pw_gid, groups, &groupCount);
