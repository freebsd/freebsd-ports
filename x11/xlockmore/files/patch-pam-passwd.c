--- ../xlockmore-5.20.1.orig/xlock/passwd.c	Mon Sep 26 17:11:20 2005
+++ xlock/passwd.c	Mon Dec 12 15:04:31 2005
@@ -304,6 +304,16 @@
 	reply = (struct pam_response *) malloc(sizeof (struct pam_response) *
 					       num_msg);
 
+// reply[] members is not initialized!
+// As a result - abort trap when PAM tries to free reply structure
+// after PAM_ERROR_MSG processing.
+
+// So I just initialize reply here with default values and drop
+// initialization from code below (if code matches).
+
+	reply[replies].resp_retcode = PAM_SUCCESS; // be optimistic
+	reply[replies].resp = NULL;
+
 	if (!reply)
 		return PAM_CONV_ERR;
 
@@ -325,7 +335,6 @@
 			  }
 			  else
 			  {
-			    reply[replies].resp_retcode = PAM_SUCCESS;
 			    reply[replies].resp = COPY_STRING(PAM_password);
 			  }
 #ifdef DEBUG
@@ -340,11 +349,6 @@
 			  {
 			    PAM_putText( msg[replies], &reply[replies], False );
 			  }
-			  else
-			  {
-			    reply[replies].resp_retcode = PAM_SUCCESS;
-			    reply[replies].resp = NULL;
-			  }
 #ifdef DEBUG
 			        (void) printf( "Back From PAM_putText: PAM_PROMPT_ECHO_ON\n" );
 			        (void) printf( "Response is: (%s)\n, Return Code is: (%d)\n",
@@ -357,11 +361,7 @@
 			  {
 			    PAM_putText( msg[replies], &reply[replies], False );
 			  }
-			  else
-			  {
-			    reply[replies].resp_retcode = PAM_SUCCESS;
-			    reply[replies].resp = NULL;
-			  }
+				/* PAM frees resp */
 #ifdef DEBUG
 			        (void) printf( "Back From PAM_putText: PAM_PROMPT_ECHO_ON\n" );
 			        (void) printf( "Response is: (%s)\n, Return Code is: (%d)\n",
@@ -1205,8 +1205,7 @@
 	pam_error = pam_authenticate(pamh, 0);
 	if (pam_error != PAM_SUCCESS) {
                 if (!allowroot) {
-                        pam_end(pamh, 0);
-                        return False;
+					PAM_BAIL;
                 }
 
 		/* Try as root; bail if no success there either */
