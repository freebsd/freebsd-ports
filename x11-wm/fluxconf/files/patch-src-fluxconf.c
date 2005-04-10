--- src/fluxconf.c.orig	Thu Dec  9 01:58:37 2004
+++ src/fluxconf.c	Mon Mar 21 18:10:27 2005
@@ -146,7 +146,9 @@
 void sauver(GtkButton * button, char **laliste) /* FIXME without first parameter function hangs ... */
 {
     int n, x;
+    int source_fd, dest_fd, rdlen;
     char *fullpath = NULL;
+    char tmp_buff[BUFSIZ + 1], * ptr = NULL;
     FILE *file = NULL;
     GList *widlist = NULL;
     GtkWidget *tmpwid, *smallwin;
@@ -166,8 +168,6 @@
     /*
     * try to make a backup 
     */
-    char tmp_buff[BUFSIZ + 1], * ptr = NULL;
-    int source_fd, dest_fd, rdlen;
 
     memset(tmp_buff, 0, BUFSIZ + 1);
 
