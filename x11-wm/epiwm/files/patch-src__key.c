--- src/key.c.orig	Sat Feb  3 08:53:20 2001
+++ src/key.c	Sun Jun 24 01:04:43 2007
@@ -50,8 +50,8 @@
     tokens[i] = NULL;
   i = 0;
   strncpy(tmpstring, line, 100);
-  (char *) tokens[i] = (char *) strtok(tmpstring, "+");
-  while (((char *) tokens[++i] = (char *) strtok(NULL, "+")));
+  tokens[i] = (char *) strtok(tmpstring, "+");
+  while ((tokens[++i] = (char *) strtok(NULL, "+")));
   tokens[i] = NULL;
   return (tokens[index]);
 }
