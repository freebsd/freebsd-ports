--- kdm/backend/xdmcp.c.orig	Wed May  8 14:21:31 2002
+++ kdm/backend/xdmcp.c	Wed Jun 26 20:14:02 2002
@@ -1012,7 +1012,7 @@
 
     sprintf (buf, "Session %ld failed for display %.260s: %s",
 	     (long) sessionID, name, reason);
-    Debug ("send_failed(%\"s)\n", buf);
+    Debug ("send_failed(\"%s\")\n", buf);
     status.length = strlen (buf);
     status.data = (CARD8Ptr) buf;
     header.version = XDM_PROTOCOL_VERSION;
