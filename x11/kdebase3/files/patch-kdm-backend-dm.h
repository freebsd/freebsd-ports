--- kdm/backend/dm.h
+++ kdm/backend/dm.h
@@ -104,7 +104,6 @@
 # define Jmp_buf sigjmp_buf
 #endif
 
-#include <utmp.h>
 #ifdef HAVE_UTMPX
 # include <utmpx.h>
 # define STRUCTUTMP struct utmpx
@@ -117,6 +116,7 @@
 # define ut_time ut_tv.tv_sec
 # define ll_time ll_tv.tv_sec
 #else
+# include <utmp.h>
 # define STRUCTUTMP struct utmp
 # define UTMPNAME utmpname
 # define SETUTENT setutent
@@ -124,9 +124,9 @@
 # define PUTUTLINE pututline
 # define ENDUTENT endutent
 # define LASTLOG lastlog
-#endif
-#ifndef HAVE_STRUCT_UTMP_UT_USER
-# define ut_user ut_name
+# ifndef HAVE_STRUCT_UTMP_UT_USER
+#  define ut_user ut_name
+# endif
 #endif
 #ifndef WTMP_FILE
 # ifdef _PATH_WTMPX
