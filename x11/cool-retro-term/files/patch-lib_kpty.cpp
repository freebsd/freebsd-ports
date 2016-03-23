--- qmltermwidget/lib/kpty.cpp.orig
+++ qmltermwidget/lib/kpty.cpp
@@ -28,7 +28,7 @@
 
 
 #if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
-#define HAVE_LOGIN
+//#define HAVE_LOGIN
 #define HAVE_LIBUTIL_H
 #endif
 
@@ -84,9 +84,10 @@ extern "C" {
 # include <utempter.h>
 }
 #else
-# include <utmp.h>
 # ifdef HAVE_UTMPX
 #  include <utmpx.h>
+# else
+#  include <utmp.h>
 # endif
 # if !defined(_PATH_UTMPX) && defined(_UTMPX_FILE)
 #  define _PATH_UTMPX _UTMPX_FILE
@@ -503,7 +504,7 @@ void KPty::login(const char * user, cons
     // note: strncpy without terminators _is_ correct here. man 4 utmp
 
     if (user) {
-        strncpy(l_struct.ut_name, user, sizeof(l_struct.ut_name));
+        strncpy(l_struct.ut_user, user, sizeof(l_struct.ut_user));
     }
 
     if (remotehost) {
@@ -550,7 +551,7 @@ void KPty::login(const char * user, cons
 #   endif
 #  endif
 #  ifdef HAVE_UTMPX
-    utmpxname(_PATH_UTMPX);
+    //utmpxname(_PATH_UTMPX);
     setutxent();
     pututxline(&l_struct);
     endutxent();
@@ -606,7 +607,7 @@ void KPty::logout()
     strncpy(l_struct.ut_line, str_ptr, sizeof(l_struct.ut_line));
 
 #  ifdef HAVE_UTMPX
-    utmpxname(_PATH_UTMPX);
+    //utmpxname(_PATH_UTMPX);
     setutxent();
     if ((ut = getutxline(&l_struct))) {
 #  else
@@ -614,7 +615,7 @@ void KPty::logout()
     setutent();
     if ((ut = getutline(&l_struct))) {
 #  endif
-        memset(ut->ut_name, 0, sizeof(*ut->ut_name));
+        memset(ut->ut_user, 0, sizeof(*ut->ut_user));
         memset(ut->ut_host, 0, sizeof(*ut->ut_host));
 #  ifdef HAVE_STRUCT_UTMP_UT_SYSLEN
         ut->ut_syslen = 0;
