--- src/switchuser.c.orig	Sun Oct 24 04:15:32 2004
+++ src/switchuser.c	Sat Jan  8 18:37:49 2005
@@ -77,7 +77,7 @@
    char*  correct;
    struct passwd *pw;
 #ifdef SHADOW_PASSWD
-   struct spwd* sp;
+   struct passwd* sp;
 #endif
 
    pw = getpwnam(username);
@@ -87,10 +87,10 @@
    }
 
 #ifdef SHADOW_PASSWD
-   sp = getspnam(pw->pw_name);    
-   endspent();
+   sp = getpwnam(pw->pw_name);    
+   endpwent();
    if(sp) {
-      correct = sp->sp_pwdp;
+      correct = sp->pw_passwd;
    }
    else
 #endif
