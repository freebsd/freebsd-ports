--- src/main.c.orig	Thu Dec 27 11:29:55 2001
+++ src/main.c	Thu Dec 27 11:33:43 2001
@@ -30,6 +30,7 @@
 #include <getopt.h>
 
 #include <sys/types.h>
+#include <sys/time.h>
 #include <sys/resource.h>
 #include <sys/wait.h>
 
@@ -150,7 +151,7 @@
 contains(const char *s, const char *kw, XsetInputType t, int *p1, int *p2)
 {
     const char *found;
-    const char stmp[128];
+    char stmp[128];
     int itmp, itmp2;
 
     found = strstr(s, kw);
@@ -655,12 +656,12 @@
 	printf("Usage: %s [OPTION ...] FILE ...\n", g_get_prgname());
 
 	fputs ("\n\
--h, --help		display this help and exit\n\
--V, --version		output version information and exit\n\
+-h, display this help and exit\n\
+-V, output version information and exit\n\
 \n\
--n, --dry-run		print xset commands to stdout\n\
--c, --no-confirm-dialog	don't use the default confirmation dialogs\n\
--e, --no-error-dialogs	print error messages to stderr\n\
+-n, print xset commands to stdout\n\
+-c, don't use the default confirmation dialogs\n\
+-e, print error messages to stderr\n\
 \n\
 Report bugs to René Seindal <rene@seindal.dk>.\n",
 	       stdout);
@@ -689,8 +690,7 @@
     gtk_set_locale ();
     gtk_init (&argc, &argv);
 
-    while ((optchar = getopt_long(argc, argv, OPTSTRING, 
-				  long_options, NULL)) != EOF)
+    while ((optchar = getopt(argc, argv, OPTSTRING)) != EOF)
     {
 	switch (optchar)
 	{
