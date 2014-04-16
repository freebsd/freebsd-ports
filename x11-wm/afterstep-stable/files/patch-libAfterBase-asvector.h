$FreeBSD$

--- libAfterBase/asvector.h.orig	2014-04-12 12:22:00.000000000 -0700
+++ libAfterBase/asvector.h	2014-04-12 12:22:37.000000000 -0700
@@ -38,7 +38,7 @@
 /* returns index on success, -1 on failure */
 int vector_insert_elem( ASVector *v, void *data, size_t size, void *sibling, int before );
 int vector_relocate_elem (ASVector *v, unsigned int index, unsigned int new_index);
-inline size_t vector_find_data (ASVector *v, void *data );
+size_t vector_find_data (ASVector *v, void *data );
 int vector_find_elem( ASVector *v, void *data );
 /* returns 1 on success, 0 on failure */
 int vector_remove_elem( ASVector *v, void *data );
