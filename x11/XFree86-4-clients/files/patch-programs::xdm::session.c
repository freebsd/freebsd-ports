--- programs/xdm/session.c.old	Wed Jun 30 22:12:02 2004
+++ programs/xdm/session.c	Wed Jun 30 22:12:21 2004
@@ -54,8 +54,12 @@
 #ifdef SECURE_RPC
 # include <rpc/rpc.h>
 # include <rpc/key_prot.h>
+#ifdef FREEBSD_OLD_RPC
+extern int key_setnet(struct netstarg *arg);
+#else
 extern int key_setnet(struct key_netstarg *arg);
 #endif
+#endif
 #ifdef K5AUTH
 # include <krb5/krb5.h>
 #endif
@@ -643,7 +647,11 @@
 	    char    netname[MAXNETNAMELEN+1], secretkey[HEXKEYBYTES+1];
 	    int	    nameret, keyret;
 	    int	    len;
+#ifdef FREEBSD_OLD_RPC
+	    struct  netstarg netst;
+#else
 	    struct  key_netstarg netst;
+#endif
 	    int     key_set_ok = 0;
 
 	    nameret = getnetname (netname);
