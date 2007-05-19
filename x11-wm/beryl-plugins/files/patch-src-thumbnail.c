--- src/thumbnail.c.orig	Wed Jan 31 18:22:05 2007
+++ src/thumbnail.c	Sat Feb 10 11:46:43 2007
@@ -219,7 +219,10 @@
 		return NULL;
 	}
 
-	retval = strndup (val, nitems);
+	if ((retval = (char *) malloc(nitems + 1)) != NULL) {
+		bzero (retval, nitems + 1);
+		strncpy (retval, val, nitems);
+	}
 
 	XFree (val);
 
@@ -234,7 +237,10 @@
 	text.nitems = 0;
 	if (XGetTextProperty (d->display, id, &text, atom))
 	{
-		retval = strndup ((char *)text.value,text.nitems);
+		if ((retval = (char *) malloc(text.nitems + 1)) != NULL) {
+			bzero (retval, text.nitems + 1);
+			strncpy (retval, (char *)text.value, text.nitems);
+		}
 		if (text.value)
 			XFree (text.value);
 	}
