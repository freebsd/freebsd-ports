--- ./kdm/backend/xdmcp.c.orig	Sun Mar 24 12:31:09 2002
+++ ./kdm/backend/xdmcp.c	Thu Apr 18 20:53:44 2002
@@ -510,10 +510,8 @@
 	    j = 0;
 	    for (i = 0; i < (int)clientPort.length; i++)
 		j = j * 256 + clientPort.data[i];
-	    Debug ("Forward client address (port %d)", j);
-	    for (i = 0; i < (int)clientAddress.length; i++)
-		Debug (" %d", clientAddress.data[i]);
-	    Debug ("\n");
+	    Debug ("Forward client address (port %d) %[*hhu\n", j,
+		   clientAddress.length, clientAddress.data);
     	    switch (from->sa_family)
     	    {
 #ifdef AF_INET
@@ -1014,7 +1012,7 @@
 
     sprintf (buf, "Session %ld failed for display %.260s: %s",
 	     (long) sessionID, name, reason);
-    Debug ("send_failed(\"%s\")", buf);
+    Debug ("send_failed(%\"s)\n", buf);
     status.length = strlen (buf);
     status.data = (CARD8Ptr) buf;
     header.version = XDM_PROTOCOL_VERSION;
