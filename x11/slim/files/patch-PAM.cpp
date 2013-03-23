--- PAM.cpp.orig	2012-06-26 12:20:14.000000000 +0400
+++ PAM.cpp	2012-12-16 16:05:09.000000000 +0400
@@ -128,6 +128,7 @@
             case PAM_MAXTRIES:
             case PAM_CRED_INSUFFICIENT:
             case PAM_AUTH_ERR:
+            case PAM_CONV_ERR:
                 throw Auth_Exception(pam_handle, "pam_authentication()", last_result);
 
             case PAM_SUCCESS:
