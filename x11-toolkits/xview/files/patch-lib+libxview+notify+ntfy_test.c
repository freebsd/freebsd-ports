--- ./lib/libxview/notify/ntfy_test.c.orig	Tue Jun 29 07:18:12 1993
+++ ./lib/libxview/notify/ntfy_test.c	Sat Apr  1 18:25:26 2000
@@ -989,7 +989,7 @@ nt_try_send_event(client, cond)
 	    fprintf(stderr, "%s in unknown destroy status\n", arg1);
 	    goto Error;
 	}
-	if ((ne = notify_post_destroy(client, status)) != NOTIFY_OK) {
+	if ((ne = notify_post_destroy(client, status), NOTIFY_IMMEDIATE) != NOTIFY_OK) {
 	    if (!(status == DESTROY_CHECKING &&
 		  ne == NOTIFY_DESTROY_VETOED)) {
 		notify_perror("notify_destroy");
@@ -1781,7 +1781,7 @@ nt_prioritizer(nclient, nfd, ibits_ptr, 
     }
     /* Send only last client event */
     if (*event_count_ptr > 0) {
-	(void) notify_event(nclient, *(events + (*event_count_ptr) - 1));
+	(void) notify_event(nclient, *(events + (*event_count_ptr) - 1), 0);
 	*event_count_ptr--;
     }
     /* Send fd 1 input */
