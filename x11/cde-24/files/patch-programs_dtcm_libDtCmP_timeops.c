--- programs/dtcm/libDtCmP/timeops.c.orig	2023-01-16 10:43:01.353775000 -0800
+++ programs/dtcm/libDtCmP/timeops.c	2023-01-16 10:50:35.918370000 -0800
@@ -960,7 +960,7 @@
 	 */
 	if (tzname==NULL) system("unset TZ\n");
 #else
-	if (tzname==NULL) tzsetwall();
+	if (tzname==NULL) tzset();
 #endif /* SVR4 */
 
 	else {
