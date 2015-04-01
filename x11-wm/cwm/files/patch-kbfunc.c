--- kbfunc.c.orig	2015-03-26 00:09:51 UTC
+++ kbfunc.c
@@ -324,7 +324,7 @@ kbfunc_ssh(struct client_ctx *cc, union 
 	struct menu_q		 menuq;
 	FILE			*fp;
 	char			*buf, *lbuf, *p;
-	char			 hostbuf[HOST_NAME_MAX+1];
+	char			 hostbuf[_POSIX_HOST_NAME_MAX+1];
 	char			 path[PATH_MAX];
 	int			 l;
 	size_t			 len;
