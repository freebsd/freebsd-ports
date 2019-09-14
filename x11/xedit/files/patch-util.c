--- util.c.orig	2015-02-21 21:42:33 UTC
+++ util.c
@@ -506,13 +506,14 @@ ResolveName(char *filename)
 
     if (result == NULL && errno == ENOENT) {
 	int	length;
-	char	*dir, *file;
+	char	*dir, *file, *fname;
 
 	length = strlen(filename);
 	tmp = dir = XtMalloc(length + 1);
 	strcpy(dir, filename);
+	fname = strdup(filename);
 
-	file = basename(filename);
+	file = basename(fname);
 	dir = dirname(tmp);
 
 	/* Creating a new file? */
@@ -526,6 +527,7 @@ ResolveName(char *filename)
 	}
 
 	XtFree(tmp);
+	free(fname);
     }
 
     return (result);
