
$FreeBSD$

--- resource.c.orig	Sat Nov 30 14:34:12 2002
+++ resource.c	Sat Aug 14 08:45:34 2004
@@ -382,8 +382,7 @@
     break;
   case XpmNoMemory:
     printf("No memory for open xpm file: %s\n", name);
-    break;
-  default:
+  default: break;
   }
 }
 
