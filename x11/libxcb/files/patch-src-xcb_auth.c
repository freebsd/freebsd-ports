--- src/xcb_auth.c.orig	2008-08-28 06:49:21.000000000 -0500
+++ src/xcb_auth.c	2009-04-04 13:37:45.000000000 -0500
@@ -251,7 +251,12 @@
 
     info->namelen = memdup(&info->name, authptr->name, authptr->name_length);
     if(info->namelen)
-	ret = compute_auth(info, authptr, sockname);
+    {
+        if (getsockname(fd, sockname, &socknamelen) == -1)
+            ret = 0;
+        else
+            ret = compute_auth(info, authptr, sockname);
+    }
     if(!ret)
     {
 	free(info->name);
