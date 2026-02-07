--- main.c.orig	Thu Dec 23 09:57:45 2004
+++ main.c	Thu Dec 23 09:58:02 2004
@@ -43,7 +43,7 @@
     int i;
     for (i = 1; i < argc; i++)
     {
-      TRACE();
+      TRACE("%s","");
       if (strstr(argv[i], "--edit") != NULL)
       {
         launch_editor = TRUE;
