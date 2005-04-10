--- src/fluxmenu.c.orig	Fri Dec 10 23:47:14 2004
+++ src/fluxmenu.c	Mon Mar 21 18:10:27 2005
@@ -408,8 +408,10 @@
 void savemenu(void)
 {
     char *initpath, *buf;
+    char tmp_buff[BUFSIZ+1],*ptr;
     FILE *file;
     int n;
+    int source_fd, dest_fd, rdlen;
     initpath = malloc(sizeof(char) * 200);
     buf = malloc(sizeof(char)*200);
 
@@ -432,8 +434,6 @@
     /*
     * try to make a backup
     */
-    char tmp_buff[BUFSIZ+1],*ptr;
-    int source_fd, dest_fd, rdlen;
 
     memset(tmp_buff,0,BUFSIZ+1);
 
