--- ./lib/libxview/notify/ntfyclient.c.orig	Tue Jun 29 07:18:11 1993
+++ ./lib/libxview/notify/ntfyclient.c	Sat Apr  1 18:25:26 2000
@@ -18,7 +18,9 @@ static char     sccsid[] = "@(#)ntfyclie
 #include <xview_private/ntfy.h>
 #include <xview_private/ndis.h>	/* For ndis_default_prioritizer */
 #include <xview_private/ndet.h>	
+#ifndef __FreeBSD__
 #include <search.h>
+#endif
 #include <xview_private/portable.h>
 
 /* Variables used in paranoid enumerator (see ntfy_condition) */
@@ -60,6 +62,7 @@ ntfy_find_nclient(client_list, nclient, 
     if (*client_latest && (*client_latest)->nclient == nclient)
 	return (*client_latest);
 
+#ifndef __FreeBSD__
     if(( client_list == ndet_clients ) && ndet_clients ) {
        dummy_client.nclient = nclient;
        /* Find client */
@@ -73,7 +76,9 @@ ntfy_find_nclient(client_list, nclient, 
            return (client);
        }
     }
-
+#else
+    if(0);
+#endif
     else 
         /* Search entire list */
         for (client = client_list; client; client = next) {
@@ -100,6 +105,7 @@ ntfy_new_nclient(client_list, nclient, c
     register NTFY_CLIENT *client;
     static NTFY_CLIENT *new_client;
 
+#ifndef __FreeBSD__
     if( client_list == &ndet_clients ) {
         if( new_client  == NTFY_CLIENT_NULL ) {
             if ((new_client = ntfy_alloc_client()) == NTFY_CLIENT_NULL)
@@ -119,7 +125,9 @@ ntfy_new_nclient(client_list, nclient, c
         else
             return client;
     }
-
+#else
+    if(0);
+#endif
     else if ((client = ntfy_find_nclient(*client_list, nclient,
 				    client_latest)) != NTFY_CLIENT_NULL)
         return client;
@@ -163,8 +171,10 @@ ntfy_remove_client(client_list, client, 
 	ntfy_remove_condition(client, condition, who);
     }
     /* Remove & free client from client_list */
+#ifndef __FreeBSD__
     if( client_list == &ndet_clients )
         tdelete( client, ndet_root, ndet_compar );
+#endif
     ntfy_remove_node((NTFY_NODE **) client_list, (NTFY_NODE *) client);
     /* Invalidate condition hint */
     *client_latest = NTFY_CLIENT_NULL;
