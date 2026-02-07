--- ./PAM.cpp.orig	2012-12-31 07:03:42.000000000 -0600
+++ ./PAM.cpp	2013-03-23 14:10:35.000000000 -0500
@@ -127,6 +127,7 @@
 			case PAM_MAXTRIES:
 			case PAM_CRED_INSUFFICIENT:
 			case PAM_AUTH_ERR:
+			case PAM_CONV_ERR:
 				throw Auth_Exception(pam_handle, "pam_authentication()", last_result);
 
 			case PAM_SUCCESS:
