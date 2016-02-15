--- Client.C.orig	1997-03-21 11:12:30 UTC
+++ Client.C
@@ -410,7 +410,7 @@ int Client::getAtomProperty(Atom a, Atom
 
     x = *p;
     XFree((void *)p);
-    return (int)x;
+    return (intptr_t)x;
 }
 
 
