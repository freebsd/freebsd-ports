
$FreeBSD$

--- gsm/ice.c	2001/11/20 12:53:53	1.1
+++ gsm/ice.c	2001/11/20 12:53:56
@@ -337,6 +337,15 @@
 
   p = g_strconcat (ENVNAME "=", ids, NULL);
   putenv (p);
+
+  /* XXX: hack for embedded Mozilla */
+  p = getenv ("LD_LIBRARY_PATH");
+  if (p == NULL)
+    p = "";
+  else
+    p = g_strconcat (p, ":", NULL);
+  p = g_strconcat (p, X11BASE "/lib/mozilla-embedded", NULL);
+  setenv ("LD_LIBRARY_PATH", p, 1);
 }
 
 void
