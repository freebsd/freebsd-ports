$FreeBSD$

--- src/Arrange/Arrange.c.orig	Wed May 18 10:38:10 2005
+++ src/Arrange/Arrange.c	Wed May 18 10:39:48 2005
@@ -488,15 +488,14 @@
 {
 	int buf_size = 256;
 	char buf[buf_size];
-	
-	ASWindowData *wd = fetch_window_by_id( ((client_item *) data)->cl );
-	if(!wd)
-		return True;
-
 	/* used by SendNumCommand */
 	send_signed_data_type vals[2] ;	
 	send_signed_data_type units[2] ;
 
+	ASWindowData *wd = fetch_window_by_id( ((client_item *) data)->cl );
+	if(!wd)
+		return True;
+
 	if(! window_is_suitable( wd ))
 	  return True; /* Next window please */
 
@@ -550,6 +549,7 @@
 void 
 tile_windows()
 {
+	int n_groups;
 	int n_windows = 0;
 	iterate_asbidirlist( ArrangeState.clients_order,
 			     count_managed_windows, &n_windows, NULL, False);
@@ -561,7 +561,7 @@
 	if(ArrangeState.count == 0)
 	  ArrangeState.count = n_windows; /*Put all elements in one group*/
 	
-	int n_groups = n_windows / ArrangeState.count;
+	n_groups = n_windows / ArrangeState.count;
 	/* If not all windows fit in n_groups groups, an
 	 * extra group for remaining windows is needed.*/
 	if(n_windows % ArrangeState.count)
@@ -614,13 +614,12 @@
 {
 	int buf_size = 256;
 	char buf[buf_size];
+	send_signed_data_type vals[2] ;	
+	send_signed_data_type units[2] ;	
 	
 	ASWindowData *wd = fetch_window_by_id( ((client_item *) data)->cl );
 	if(!wd)
 		return True;
-
-	send_signed_data_type vals[2] ;	
-	send_signed_data_type units[2] ;	
 
 	if(! window_is_suitable( wd ))
 	  return True; /* Next window please */
