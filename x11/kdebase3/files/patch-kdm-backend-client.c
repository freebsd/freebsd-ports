--- kdm/backend/client.c	18 Jun 2003 20:05:15 -0000	2.25.2.4
+++ kdm/backend/client.c	6 Aug 2003 16:02:39 -0000	2.25.2.5
@@ -1,5 +1,5 @@
 /* $TOG: verify.c /main/37 1998/02/11 10:00:45 kaleb $ */
-/* $Id: client.c,v 2.25.2.4 2003/06/18 20:05:15 ossi Exp $ */
+/* $Id: client.c,v 2.25.2.5 2003/08/06 16:02:39 ossi Exp $ */
 /*
 
 Copyright 1988, 1998  The Open Group
@@ -1009,7 +1009,11 @@ StartClient (struct display *d,
 	    exit (1);
 # endif
 # ifdef USE_PAM
-	pam_setcred(pamh, 0);
+	if (pam_setcred(pamh, 0) != PAM_SUCCESS) {
+	    LogError("pam_setcred for %\"s failed, errno=%d\n",
+		     name, errno);
+	    exit (1);
+	}
 	/* pass in environment variables set by libpam and modules it called */
 	pam_env = pam_getenvlist(pamh);
 	ReInitErrorLog ();
@@ -1267,7 +1271,9 @@ SessionExit (struct display *d, int stat
 #ifdef USE_PAM
 	if (pamh) {
 	    /* shutdown PAM session */
-	    pam_setcred(pamh, PAM_DELETE_CRED);
+	    if (pam_setcred(pamh, PAM_DELETE_CRED) != PAM_SUCCESS)
+		LogError("pam_setcred(DELETE_CRED) for %\"s failed, errno=%d\n",
+			 d->verify->user, errno);
 	    pam_close_session(pamh, 0);
 	    pam_end(pamh, PAM_SUCCESS);
 	    pamh = NULL;
