--- ./kdm/backend/dm.c.orig	Sun Mar 24 12:31:09 2002
+++ ./kdm/backend/dm.c	Thu Apr 18 20:53:44 2002
@@ -236,7 +236,6 @@
 	else
 	    break;
     }
-    InitErrorLog (errorLogFile);
 
     /*
      * Only allow root to run in non-debug mode to avoid problems
@@ -246,6 +245,8 @@
 	fprintf (stderr, "Only root wants to run %s\n", prog);
 	exit (1);
     }
+
+    InitErrorLog (errorLogFile);
 
     /*
      * Step 1 - load configuration parameters
