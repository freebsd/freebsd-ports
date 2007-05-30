--- xcoloredit.c.orig	Wed May 30 22:10:09 2007
+++ xcoloredit.c	Wed May 30 22:10:57 2007
@@ -85,6 +85,7 @@
 static void move_scroll();
 static void change_text_colour();
 
+static int WhichButton(String name);
 
 #define MEMORY_OFFSET	8
 #define NUM_MEMORIES	36
