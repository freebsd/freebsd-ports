--- ./kdm/backend/protodpy.c.orig	Sun Mar 24 12:31:09 2002
+++ ./kdm/backend/protodpy.c	Thu Apr 18 20:53:44 2002
@@ -48,12 +48,13 @@
 PrintProtoDisplay (pdpy)
     struct protoDisplay	*pdpy;
 {
-    Debug ("ProtoDisplay %p\n", pdpy);
-    Debug ("\taddress: ");
-    PrintSockAddr (pdpy->address, pdpy->addrlen);
-    Debug ("\tdate %d (%d from now)\n", pdpy->date, time(0) - pdpy->date);
-    Debug ("\tdisplay Number %d\n", pdpy->displayNumber);
-    Debug ("\tsessionID %d\n", pdpy->sessionID);
+    char addrbuf[128];
+
+    PrintSockAddr (addrbuf, pdpy->address, pdpy->addrlen);
+    Debug ("ProtoDisplay %p\n\taddress: %s\n\tdate %d (%d from now)\n"
+           "\tdisplay Number %d\n\tsessionID %d\n",
+	   pdpy, addrbuf, pdpy->date, time(0) - pdpy->date,
+	   pdpy->displayNumber, pdpy->sessionID);
 }
 #endif
 
