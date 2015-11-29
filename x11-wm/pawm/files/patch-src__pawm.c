--- src/pawm.c.orig	2010-05-03 02:36:18 UTC
+++ src/pawm.c
@@ -114,7 +114,7 @@ static void get_pawm_conf() 
 
 int main (int argc, char *argv[]) 
 {
-	struct sigaction sa_term, sa_chld;
+	struct sigaction sa_term, sa_chld, sa_alrm;
     
     /* Command line parameters */
 	if (argc > 1) {    
