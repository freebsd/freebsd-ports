--- programs/dtcm/libDtCmP/timeops.c.orig	2023-01-16 09:59:52.166236000 -0800
+++ programs/dtcm/libDtCmP/timeops.c	2023-01-16 10:43:55.531953000 -0800
@@ -963,7 +963,7 @@
 	 */
 	if (tzname==NULL) system("unset TZ\n");
 #else
-	if (tzname==NULL) tzsetwall();
+	if (tzname==NULL) tzset();
 #endif /* SVR4 */
 
 	else {
