--- clients/olwm/st.c.orig	2005-03-28 06:39:46.000000000 -0800
+++ clients/olwm/st.c	2013-09-17 23:23:11.632099936 -0700
@@ -34,6 +34,8 @@
 	(table->hash == ST_NUMHASH) ? ((int) (key) % table->num_bins) :\
 	(*table->hash)((key), table->num_bins))
 
+static rehash(st_table *table);
+
 st_table *st_init_table_with_params(compare, hash, size, density, grow_factor,
 				    reorder_flag)
 int (*compare)();
@@ -329,7 +331,7 @@
 		ptr = ptr->next;
 		break;
 	    case ST_STOP:
-		return;
+		return 0;
 	    case ST_DELETE:
 		tmp = ptr;
 		if (last == nil(st_table_entry)) {
