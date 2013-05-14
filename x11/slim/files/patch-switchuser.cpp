--- ./switchuser.cpp.orig	2012-12-31 07:03:42.000000000 -0600
+++ ./switchuser.cpp	2013-03-23 14:10:35.000000000 -0500
@@ -36,6 +36,8 @@
 
 void SwitchUser::SetUserId() {
 	if( (Pw == 0) ||
+			(setsid() == -1) ||
+			(setlogin(Pw->pw_name) != 0) ||
 			(initgroups(Pw->pw_name, Pw->pw_gid) != 0) ||
 			(setgid(Pw->pw_gid) != 0) ||
 			(setuid(Pw->pw_uid) != 0) ) {
