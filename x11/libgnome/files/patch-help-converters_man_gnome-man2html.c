--- help-converters/man/gnome-man2html.c.orig	Thu Jul 24 14:06:36 2003
+++ help-converters/man/gnome-man2html.c	Thu Jul 24 14:06:06 2003
@@ -129,6 +129,7 @@
 #include <string.h>
 #include <sys/stat.h>
 #include <dirent.h>
+#include <sys/param.h>
 #include <sys/types.h>
 #include <time.h>
 #include <sys/time.h>
@@ -3727,6 +3728,9 @@
 main(int argc, char **argv)
 {
 	char *t=NULL;
+#ifdef __FreeBSD__
+	char *source=NULL;
+#endif
 	int i,len;
 	char *buf;
 	char *h = '\0';
@@ -3845,6 +3849,20 @@
 		 * right.
 		 */
 		
+#ifdef __FreeBSD__
+		if ((source =  strstr(output, "source: ")) != NULL)
+		{
+		    	int j;
+		    	for(i = 8, j = 0; i < strlen(source); i++)
+			{
+			    	if (!g_ascii_isspace((unsigned char)source[i]) && source[i] != ')')
+				{
+				    	output[j++] = source[i];
+				}
+			}
+			output[j] = '\0';
+		}
+#else
 		len = strlen(output);
 		for(i = 0; i < len; i++)
 		{
@@ -3855,8 +3873,7 @@
 		i = strlen(output) - 1;
 		while (g_ascii_isspace((unsigned char)output[i])) 
 			output[i--] = '\0';
-
-		
+#endif
 		if (output[0]) {
 #ifdef HAVE_LIBBZ2
 		  if(strstr(output,".bz2"))
