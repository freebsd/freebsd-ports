--- action.c.orig	Fri Oct 25 11:18:06 2002
+++ action.c	Fri Oct 25 11:18:39 2002
@@ -178,7 +178,7 @@
 {
         int     	pid;
 	int		i = 0;
-        union wait      status;
+        int             status;
 
 
         /*
