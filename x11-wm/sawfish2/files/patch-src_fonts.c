--- src/fonts.c.orig	Sun Nov  3 22:00:36 2002
+++ src/fonts.c	Wed Feb  8 04:22:13 2006
@@ -131,7 +131,7 @@
 	    if (end == 0)
 		end = p + strlen (p);
 	    len = end - (p + 1);
-	    buf = malloc (len);
+	    buf = malloc (len + 1);
 	    memcpy (buf, p + 1, len);
 	    buf[len] = 0;
 	    return buf;
