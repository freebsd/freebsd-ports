--- ./kdm/backend/netaddr.c.orig	Sun Mar 24 12:31:09 2002
+++ ./kdm/backend/netaddr.c	Thu Apr 18 20:53:44 2002
@@ -216,11 +216,10 @@
 #ifdef DEBUG
 /*ARGSUSED*/
 void
-PrintSockAddr (struct sockaddr *a, int len)
+PrintSockAddr (char *buf, struct sockaddr *a, int len)
 {
     unsigned char    *t, *p;
 
-    Debug ("family %d, ", a->sa_family);
     switch (a->sa_family) {
 #ifdef AF_INET
     case AF_INET:
@@ -228,11 +227,14 @@
 	p = (unsigned char *) &((struct sockaddr_in *) a)->sin_port;
 	t = (unsigned char *) &((struct sockaddr_in *) a)->sin_addr;
 
-	Debug ("port %d, host %d.%d.%d.%d\n",
-		(p[0] << 8) + p[1], t[0], t[1], t[2], t[3]);
+	sprintf (buf, "family AF_INET, port %d, host %d.%d.%d.%d",
+		 (p[0] << 8) + p[1], t[0], t[1], t[2], t[3]);
 	break;
-    }
 #endif
+    default:
+	sprintf (buf, "unknown family %d", a->sa_family);
+	break;
+    }
 }
 #endif
 
