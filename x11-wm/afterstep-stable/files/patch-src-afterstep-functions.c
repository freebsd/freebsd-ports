$FreeBSD$

--- src/afterstep/functions.c.orig	Sat Feb 19 21:12:04 2005
+++ src/afterstep/functions.c	Sat Feb 19 21:12:25 2005
@@ -1441,6 +1441,7 @@
 		}
 		if( realfilename == NULL )
 		{
+			char default_template[128];
 			char capture_file_name[80];
 			if (data->func == F_TAKE_WINDOWSHOT)
 			{
@@ -1454,7 +1455,6 @@
 			{
 			    strcpy(capture_file_name, DEFAULT_CAPTURE_SCREEN_FILE);
 			}
-			char default_template[128];
 			sprintf(&(default_template[0]), strcat(capture_file_name, ".%lu.png"), time(NULL));
 			realfilename = PutHome(&(default_template[0]));
 			compress = "9" ;
