--- util/xgettext/xgettext.h.orig	2005-03-28 06:41:59.000000000 -0800
+++ util/xgettext/xgettext.h	2012-02-03 13:13:01.859402717 -0800
@@ -8,7 +8,7 @@
 #include <signal.h>
 #include <sys/types.h>
 
-#if defined SVR4 || defined __CYGWIN__
+#if defined SVR4 || defined __CYGWIN__ || defined __FreeBSD__
 #include <dirent.h>
 #else
 #include <sys/dir.h>
