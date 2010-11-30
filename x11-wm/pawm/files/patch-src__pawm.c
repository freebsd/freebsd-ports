--- src/pawm.c.orig	2010-05-03 11:36:18.000000000 +0900
+++ src/pawm.c	2010-09-22 01:27:38.000000000 +0900
@@ -114,7 +114,7 @@
 
 int main (int argc, char *argv[]) 
 {
-	struct sigaction sa_term, sa_chld;
+	struct sigaction sa_term, sa_chld, sa_alrm;
     
     /* Command line parameters */
 	if (argc > 1) {    
