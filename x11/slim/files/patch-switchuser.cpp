--- switchuser.cpp.orig	2013-10-01 18:38:05.000000000 -0400
+++ switchuser.cpp	2014-12-15 22:14:16.000000000 -0500
@@ -9,6 +9,9 @@
    (at your option) any later version.
 */
 
+#include <sys/types.h>
+#include <login_cap.h>
+
 #include <cstdio>
 #include "switchuser.h"
 #include "util.h"
@@ -35,13 +38,27 @@
 }
 
 void SwitchUser::SetUserId() {
-	if( (Pw == 0) ||
-			(initgroups(Pw->pw_name, Pw->pw_gid) != 0) ||
-			(setgid(Pw->pw_gid) != 0) ||
-			(setuid(Pw->pw_uid) != 0) ) {
-		logStream << APPNAME << ": could not switch user id" << endl;
-		exit(ERR_EXIT);
+	if ((Pw != 0) && (setsid() != -1)) {
+		// TODO: allow users to override settings with .login.conf
+		login_cap_t *lc = login_getpwclass(Pw);
+		if ((lc != NULL) &&
+				(setusercontext(lc, Pw, Pw->pw_uid, LOGIN_SETALL) == 0)) {
+			login_close(lc);
+			return;
+		}
+		login_close(lc);
+		logStream << APPNAME << ": fail to set user context" << endl;
+		// fallback to old method
+		if ((setlogin(Pw->pw_name) == 0) &&
+				(initgroups(Pw->pw_name, Pw->pw_gid) == 0) &&
+				(setgid(Pw->pw_gid) == 0) &&
+				(setuid(Pw->pw_uid) == 0) ) {
+			return;
+		}
 	}
+
+	logStream << APPNAME << ": could not switch user id" << endl;
+	exit(ERR_EXIT);
 }
 
 void SwitchUser::Execute(const char* cmd) {
