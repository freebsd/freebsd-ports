
$FreeBSD$

--- resource.c.orig	Fri Aug 13 22:34:08 2004
+++ resource.c	Fri Aug 13 22:34:19 2004
@@ -383,7 +383,6 @@
   case XpmNoMemory:
     printf("No memory for open xpm file: %s\n", name);
     break;
-  default:
   }
 }
 
