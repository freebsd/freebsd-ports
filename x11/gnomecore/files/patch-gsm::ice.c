
$FreeBSD$

--- gsm/ice.c.orig	Fri Oct 26 12:13:22 2001
+++ gsm/ice.c	Tue Jan 22 16:28:18 2002
@@ -343,6 +343,15 @@
 
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
   
   ice_depth = 0;	/* We are live */
 }
