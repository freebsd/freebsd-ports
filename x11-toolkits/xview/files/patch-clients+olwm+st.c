--- clients/olwm/st.c.orig	Sat Mar 25 22:22:56 2006
+++ clients/olwm/st.c	Sat Mar 25 22:23:59 2006
@@ -34,6 +34,8 @@
 	(table->hash == ST_NUMHASH) ? ((int) (key) % table->num_bins) :\
 	(*table->hash)((key), table->num_bins))
 
+static rehash(st_table *table);
+
 st_table *st_init_table_with_params(compare, hash, size, density, grow_factor,
 				    reorder_flag)
 int (*compare)();
