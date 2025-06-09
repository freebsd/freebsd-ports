--- programs/dtcm/libDtCmP/timeops.c.orig	2023-01-16 09:58:33.955866000 -0800
+++ programs/dtcm/libDtCmP/timeops.c	2023-01-16 10:47:36.739851000 -0800
@@ -963,7 +963,7 @@
 	 */
 	if (tzname==NULL) system("unset TZ\n");
 #else
-	if (tzname==NULL) tzsetwall();
+	if (tzname==NULL) tzset();
 #endif /* SVR4 */
 
 	else {
