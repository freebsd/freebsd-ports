$FreeBSD$

--- src/Arrange/Arrange.c.orig	Wed May  4 14:15:17 2005
+++ src/Arrange/Arrange.c	Wed May  4 14:16:39 2005
@@ -457,11 +457,12 @@
 void 
 tile_windows()
 {
+	int n_groups;
 	int n_windows = 0;
 	iterate_asbidirlist( ArrangeState.clients_order,
 			     count_managed_windows, &n_windows, NULL, False);
 	
-	int n_groups = ArrangeState.clients_order->count / ArrangeState.count;
+	n_groups = ArrangeState.clients_order->count / ArrangeState.count;
 	if(ArrangeState.clients_order->count % ArrangeState.count)
 		n_groups++;
 	
@@ -505,12 +506,11 @@
 Bool 
 cascade_window(void *data, void *aux_data)
 {
+	send_signed_data_type vals[2] ;	
+	send_signed_data_type units[2] ;	
 	ASWindowData *wd = fetch_window_by_id( ((client_item *) data)->cl );
 	if(wd == NULL)
 		return True;
-
-	send_signed_data_type vals[2] ;	
-	send_signed_data_type units[2] ;	
 
 	if(! window_is_suitable( wd ))
 	  return True; /* Next window please */
