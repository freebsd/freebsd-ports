--- cnslock.c.orig	Sun Oct 27 09:32:56 2002
+++ cnslock.c	Mon Jul  7 04:47:44 2003
@@ -212,29 +212,26 @@
     int c = 0;
 
     struct option long_options[] = {
-      {"help",         no_argument,       NULL,          1},
-      {"h",            no_argument,       NULL,          1},
-      {"version",      no_argument,       NULL,          2},
-      {"v",            no_argument,       NULL,          2},
-	  {"window",       no_argument,       NULL,          3},
-	  {"w",            no_argument,       NULL,          3},
+      {"help",         no_argument,       NULL,        'h'},
+      {"version",      no_argument,       NULL,        'v'},
+	  {"window",       no_argument,       NULL,        'w'},
 
       {0,              0,                 0,             0}
     };
 
-    while ((c = getopt_long_only(argc, argv, "", long_options, NULL)) != -1)
+    while ((c = getopt_long(argc, argv, "", long_options, NULL)) != -1)
 	{
 		switch(c)
 	  	{
-      		case 1:
+      		case 'h':
 				do_help();
 				exit(0);
 				break;
-			case 2:
+			case 'v':
 				do_version();
 				exit(0);
 				break;
-			case 3:
+			case 'w':
 				manager_style = 1;
 				break;
 		}
