--- src/style_init.c.orig	Sat Feb  3 08:53:20 2001
+++ src/style_init.c	Sun Jun 24 01:05:45 2007
@@ -77,8 +77,8 @@
     tokens[i] = NULL;
   i = 0;
   strncpy(tmpstring, line, 100);
-  (char *) tokens[i] = (char *) strtok(tmpstring, "\"");
-  while (((char *) tokens[++i] = (char *) strtok(NULL, "\"")));
+  tokens[i] = (char *) strtok(tmpstring, "\"");
+  while ((tokens[++i] = (char *) strtok(NULL, "\"")));
   tokens[i] = NULL;
   return (tokens[index]);
 }
