
$FreeBSD$

--- resource.c.orig	Sat Nov 30 15:34:12 2002
+++ resource.c	Sat Aug 14 11:48:57 2004
@@ -383,7 +383,7 @@
   case XpmNoMemory:
     printf("No memory for open xpm file: %s\n", name);
     break;
-  default:
+  default: break;
   }
 }
 
