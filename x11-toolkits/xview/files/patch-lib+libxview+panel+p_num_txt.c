--- lib/libxview/panel/p_num_txt.c.orig	Sun Oct  5 00:13:32 2003
+++ lib/libxview/panel/p_num_txt.c	Sun Oct  5 00:17:55 2003
@@ -707,7 +707,7 @@
 
 	event_init( &event ); /* send empty, bogus event */
         if (ip->notify)
-            (*ip->notify) (ITEM_PUBLIC(ip), event);
+            (*ip->notify) (ITEM_PUBLIC(ip), &event);
 
         /*
            UP_INACTIVE flag is set in set_value(); if
@@ -724,7 +724,7 @@
 
 	event_init( &event ); /* send empty, bogus event */
         if (ip->notify)
-            (*ip->notify) (ITEM_PUBLIC(ip), event);
+            (*ip->notify) (ITEM_PUBLIC(ip), &event);
 
         if (dp->btn_state & DOWN_INACTIVE)
             panel_autoscroll_stop_itimer( item );
