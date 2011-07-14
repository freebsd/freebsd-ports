--- freq/main.c.orig	2011-07-01 09:36:39.000000000 +0200
+++ freq/main.c	2011-07-01 09:36:50.000000000 +0200
@@ -23,7 +23,7 @@
 void quit(Widget w, void *data);
 void load(Widget w, void *data);
 
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
   argc = init_display(argc, argv, NULL);  /* setup the display */
   if (argc == 0)
