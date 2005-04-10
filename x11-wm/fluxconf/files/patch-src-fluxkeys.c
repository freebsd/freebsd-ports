--- src/fluxkeys.c.orig	Fri Dec 10 23:47:14 2004
+++ src/fluxkeys.c	Mon Mar 21 18:10:27 2005
@@ -265,7 +265,9 @@
     GtkBoxChild *child;
     GtkWidget *wid;
     int mod, n;
+    int source_fd, dest_fd, rdlen;
     char *initpath, *buf;
+    char tmp_buff[BUFSIZ + 1], *ptr;
 
 #ifdef GTK2
     G_CONST_RETURN gchar *key, *action, *execact;
@@ -305,8 +307,6 @@
     /*
     * FIXME: this is highly redundant 
     */
-    char tmp_buff[BUFSIZ + 1], *ptr;
-    int source_fd, dest_fd, rdlen;
 
     memset(tmp_buff, 0, BUFSIZ + 1);
 
