--- src/fluxbgd.c.orig	Tue Sep 30 20:40:39 2003
+++ src/fluxbgd.c	Tue Sep 30 20:42:40 2003
@@ -91,13 +91,14 @@
  int main(int argc, char **argv)
  {
 
- int c;
+ int c, line_max, current_line, last_line;
  int bOptionA = 0;
  int bError = 0;
  char * szInputFile = (char *) 0;
  char * szInterval = (char *) 0;
  char * eptr; /* seems not to be used */
  char * next_set[120];  /* maximum line size */
+ char * sys_command;
 /* TODO: next_set could be fixed to any length !*/
 
  szCommand = argv[0];
@@ -206,10 +207,9 @@
 		PrintError("Could not open file");
 		exit(EXIT_FAILURE);
 		}
-	int line_max = 0;
-	int current_line = 0;
-	int last_line = 0;
-	char *sys_command;
+	line_max = 0;
+	current_line = 0;
+	last_line = 0;
 	/* next while loop is checking how much lines are in the file */
 
 	while (fgets (next_set, sizeof(next_set), fp) != NULL)
