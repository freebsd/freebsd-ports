--- history.c.orig	Sun Dec 16 23:42:47 2001
+++ history.c	Tue Jul 16 20:14:38 2002
@@ -123,12 +123,13 @@
 			break;
 		}
 
-		buf = g_new0(gchar, len);
+		buf = g_new0(gchar, len + 1);
 		if (fread(buf, len, 1, f) != 1) {
 			g_free(buf);
 			tmp_errno = E_INVALID;
 			break;
 		}
+		buf[len] = '\0';
 
 		if (fread(&locked, sizeof(gint), 1, f) != 1) {
 			g_free(buf);
