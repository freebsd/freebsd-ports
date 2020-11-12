--- evtest.c.orig	2019-08-02 18:14:30 UTC
+++ evtest.c
@@ -43,7 +43,7 @@
 #include <config.h>
 #endif
 
-#include <linux/version.h>
+#include <sys/syslimits.h>
 #include <linux/input.h>
 
 #include <string.h>
@@ -875,7 +875,7 @@ static char* scan_devices(void)
 	char *filename;
 	int max_device = 0;
 
-	ndev = scandir(DEV_INPUT_EVENT, &namelist, is_event_device, versionsort);
+	ndev = scandir(DEV_INPUT_EVENT, &namelist, is_event_device, alphasort);
 	if (ndev <= 0)
 		return NULL;
 
@@ -923,7 +923,7 @@ static int version(void)
 #ifndef PACKAGE_VERSION
 #define PACKAGE_VERSION "<version undefined>"
 #endif
-	printf("%s %s\n", program_invocation_short_name, PACKAGE_VERSION);
+	printf("%s %s\n", getprogname(), PACKAGE_VERSION);
 	return EXIT_SUCCESS;
 }
 
@@ -935,12 +935,12 @@ static int usage(void)
 {
 	printf("USAGE:\n");
 	printf(" Capture mode:\n");
-	printf("   %s [--grab] /dev/input/eventX\n", program_invocation_short_name);
+	printf("   %s [--grab] /dev/input/eventX\n", getprogname());
 	printf("     --grab  grab the device for exclusive access\n");
 	printf("\n");
 	printf(" Query mode: (check exit code)\n");
 	printf("   %s --query /dev/input/eventX <type> <value>\n",
-		program_invocation_short_name);
+		getprogname());
 
 	printf("\n");
 	printf("<type> is one of: EV_KEY, EV_SW, EV_LED, EV_SND\n");
