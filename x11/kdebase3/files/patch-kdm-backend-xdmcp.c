++--- kdm/backend/xdmcp.c.orig  Sun May 19 10:38:01 2002
+++++ kdm/backend/xdmcp.c       Sun May 19 10:38:16 2002
++@@ -1012,7 +1012,7 @@
 
     sprintf (buf, "Session %ld failed for display %.260s: %s",
 	     (long) sessionID, name, reason);
-    Debug ("send_failed(%\"s)", buf);
+    Debug ("send_failed(%s)\n", buf);
     status.length = strlen (buf);
     status.data = (CARD8Ptr) buf;
     header.version = XDM_PROTOCOL_VERSION;
