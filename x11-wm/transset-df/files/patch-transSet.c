--- transSet.c.orig	Mon Jan  9 21:09:08 2006
+++ transSet.c	Mon Jan  9 21:10:27 2006
@@ -121,6 +121,11 @@
     {"verbose",0,NULL,'v'},
     {0,0,0,0}
   };
+  unsigned char *data;
+
+  Atom actual;
+  int format;
+  unsigned long n, left;
 
   /* wonderful utility */
   Setup_Display_And_Screen(&argc, argv);
@@ -228,12 +233,6 @@
     target_win = Select_Window(dpy);
   }
   
-  unsigned char *data;
-
-  Atom actual;
-  int format;
-  unsigned long n, left;
-
   if (!gotd) d=0.75;
 
   /* get property */
