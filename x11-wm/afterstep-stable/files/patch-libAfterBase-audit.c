--- libAfterBase/audit.c.orig	Sat Sep 25 03:45:27 2004
+++ libAfterBase/audit.c	Wed Sep 29 15:36:51 2004
@@ -498,7 +498,7 @@
 #else
 	/*fprintf( stderr, "%s: freeing %p at %s:%d\n", __FUNCTION__, m->ptr, fname, line );*/
 	safefree (m->ptr);
-	mem_destroy( (ASHashableValue)NULL, m );
+	mem_destroy( (ASHashableValue)(void*)NULL, m );
 #endif
 }
 
@@ -817,7 +817,7 @@
 */
 
 	XFreePixmap (display, pmap);
-	mem_destroy( (ASHashableValue)NULL, m );
+	mem_destroy( (ASHashableValue)(void*)NULL, m );
 	return Success;
 }
 
@@ -852,7 +852,7 @@
 	}
 
 	XFreeGC (display, gc);
-	mem_destroy( (ASHashableValue)NULL, m );
+	mem_destroy( (ASHashableValue)(void*)NULL, m );
 	return Success;
 }
 
@@ -931,17 +931,17 @@
 		/* can also be of C_MEM type if we allocated it ourselvs */
 		m = count_find_and_extract (fname, line, (void *)image, C_MEM);
 	if (m)
-		mem_destroy( (ASHashableValue)NULL, m );
+		mem_destroy( (ASHashableValue)(void*)NULL, m );
 
 	/* find and free the image->data pointer if it is in our list */
 	if( image_data )
 		if ((m = count_find_and_extract (fname, line, image_data, C_MEM)) != NULL)
-			mem_destroy( (ASHashableValue)NULL, m );
+			mem_destroy( (ASHashableValue)(void*)NULL, m );
 
 	/* find and free the image->obdata pointer if it is in our list */
 	if( image_obdata )
 		if ((m = count_find_and_extract (fname, line, image_obdata, C_MEM)) != NULL)
-			mem_destroy( (ASHashableValue)NULL, m );
+			mem_destroy( (ASHashableValue)(void*)NULL, m );
 
 	return Success;
 }
@@ -1140,7 +1140,7 @@
 	}
 
 	XFree (data);
-	mem_destroy( (ASHashableValue)NULL, m );
+	mem_destroy( (ASHashableValue)(void*)NULL, m );
 	return Success;
 }
 
