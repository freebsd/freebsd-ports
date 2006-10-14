--- src/gs-auth-pam.c.orig	Mon Aug 14 19:57:29 2006
+++ src/gs-auth-pam.c	Mon Aug 14 20:07:43 2006
@@ -204,7 +204,7 @@ pam_conversation (int                   
                         if (res) {
                                 reply [replies].resp_retcode = PAM_SUCCESS;
                         } else {
-                                reply [replies].resp_retcode = PAM_INCOMPLETE;
+                                reply [replies].resp_retcode = PAM_TRY_AGAIN;
                         }
                 }
         }
