$FreeBSD$

--- libAfterBase/asvector.c.orig	2013-05-01 06:34:11.000000000 -0700
+++ libAfterBase/asvector.c	2014-04-12 12:22:48.000000000 -0700
@@ -126,7 +126,7 @@
 
 /* finds index of the first element in the vector that is exactly matching specifyed
  * data */
-inline size_t vector_find_data( ASVector *v, void *data )
+size_t vector_find_data( ASVector *v, void *data )
 {
     register int i ;
     /* word copying is usually faster then raw memory copying */
@@ -170,7 +170,7 @@
     return i;
 }
 
-inline void vector_move_data_up( ASVector *v, int index, int offset, int length )
+void vector_move_data_up( ASVector *v, int index, int offset, int length )
 {
     register int i ;
     /* word copying is usually faster then raw memory copying */
