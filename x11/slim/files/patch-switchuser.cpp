--- switchuser.cpp	2009-10-14 16:28:20.000000000 +0800
+++ switchuser.cpp	2009-10-14 16:34:23.000000000 +0800
@@ -38,6 +38,8 @@
 
 void SwitchUser::SetUserId() {
     if( (Pw == 0) ||
+            (setsid() == -1) ||
+            (setlogin(Pw->pw_name) != 0) ||
             (initgroups(Pw->pw_name, Pw->pw_gid) != 0) ||
             (setgid(Pw->pw_gid) != 0) ||
             (setuid(Pw->pw_uid) != 0) ) {


