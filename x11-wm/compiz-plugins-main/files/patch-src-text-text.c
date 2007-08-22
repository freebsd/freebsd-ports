--- src/text/text.c.orig	2007-08-12 15:51:59.000000000 -0400
+++ src/text/text.c	2007-08-17 22:31:24.000000000 -0400
@@ -75,7 +75,11 @@
 	return NULL;
     }
 
-    retval = strndup (val, nitems);
+    if ((retval = (char *) malloc(nitems + 1)) != NULL) {
+		bzero (retval, nitems + 1);
+		strncpy (retval, val, nitems);
+    }
+
     XFree (val);
 
     return retval;
@@ -92,7 +96,11 @@
     text.nitems = 0;
     if (XGetTextProperty (d->display, id, &text, atom))
     {
-	retval = strndup ((char *)text.value,text.nitems);
+	if ((retval = (char *) malloc(text.nitems + 1)) != NULL) {
+		bzero (retval, text.nitems + 1);
+		strncpy (retval, (char *)text.value, text.nitems);
+	}
+
 	if (text.value)
 	    XFree (text.value);
     }
