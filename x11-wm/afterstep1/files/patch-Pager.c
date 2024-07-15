--- modules/Pager/Pager.c.orig	1996-08-21 14:23:33 UTC
+++ modules/Pager/Pager.c
@@ -85,7 +85,7 @@ int StickyIcons = 0;
  *	main - start of module
  *
  ***********************************************************************/
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
   char *temp, *s, *cptr;
   char *display_name = NULL;
@@ -751,7 +751,7 @@ int My_XNextEvent(Display *dpy, XEvent *event)
   
   if(FD_ISSET(fd[1], &in_fdset))
     {
-      if(count = ReadASPacket(fd[1],header,&body) > 0)
+      if((count = ReadASPacket(fd[1],header,&body)) > 0)
 	 {
 	   process_message(header[1],body);
 	   free(body);
