--- kdecore/netsupp.cpp.orig	Thu Aug 16 17:00:37 2001
+++ kdecore/netsupp.cpp	Thu Aug 16 16:52:30 2001
@@ -781,7 +781,7 @@
   if (name != NULL && ((*name == '*' && name[1] == '\0') || *name == '\0'))
     name = NULL;
   // Treat service of "*" as NULL, which I guess means no port (0)
-  if (serv != NULL && (*serv == '*' && serv[1] == '\0') || *serv == '\0')
+  if (serv != NULL && ((*serv == '*' && serv[1] == '\0') || *serv == '\0'))
     serv = NULL;
 
   if (name == NULL && serv == NULL) // what the hell do you want?
