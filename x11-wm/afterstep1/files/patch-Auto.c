--- modules/Auto/Auto.c.orig	1996-08-21 14:23:30 UTC
+++ modules/Auto/Auto.c
@@ -59,7 +59,7 @@ void DeadPipe(int nonsense);
  *	main - start of module
  *
  ***********************************************************************/
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
   FILE *file;
   char mask_mesg[80];
