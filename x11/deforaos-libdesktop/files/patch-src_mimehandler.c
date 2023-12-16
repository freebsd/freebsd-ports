--- src/mimehandler.c.orig	2023-10-28 13:36:08 UTC
+++ src/mimehandler.c
@@ -597,7 +597,7 @@ int mimehandler_load_by_name(MimeHandler * handler, St
 		return ret;
 	/* read through every XDG application folder */
 	if((path = getenv("XDG_DATA_DIRS")) == NULL || strlen(path) == 0)
-		path = "/usr/local/share:" DATADIR ":/usr/share";
+		path = DATADIR ":/usr/share";
 	if((p = string_new(path)) == NULL)
 		return -1;
 	for(q = strtok_r(p, ":", &last); q != NULL;
