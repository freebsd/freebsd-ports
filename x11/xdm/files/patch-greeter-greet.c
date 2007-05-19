--- greeter/greet.c.orig	Sat Feb  3 01:25:25 2007
+++ greeter/greet.c	Wed Apr  4 14:03:31 2007
@@ -612,6 +617,7 @@ greet_user_rtn GreetUser(
     }
     DeleteXloginResources (d, *dpy);
     CloseGreet (d);
+    login = NULL;
     Debug ("Greet loop finished\n");
     /*
      * Run system-wide initialization file
@@ -697,6 +704,8 @@ static int pamconv(int num_msg,
     m = *msg;
     r = *response;
 
+    if (login == NULL) goto pam_error;
+
     for (i = 0; i < num_msg; i++ , m++ , r++) {
 	char *username;
 	int promptId = 0;
