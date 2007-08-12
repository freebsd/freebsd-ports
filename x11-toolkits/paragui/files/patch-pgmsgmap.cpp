--- src/core/pgmsgmap.cpp.orig	2007-08-12 19:41:43.000000000 +0200
+++ src/core/pgmsgmap.cpp	2007-08-12 19:42:01.000000000 +0200
@@ -83,7 +83,7 @@
         return;
     
 	for ( li = list->begin() ; li != list->end() ; li++ ) {
-		PG_LogDBG(" - Message Object: %d Event Handler Data: %d", (int)(*li).first, (int)(*li).second);
+		PG_LogDBG(" - Message Object: %d Event Handler Data: %d", (intptr_t)(*li).first, (intptr_t)(*li).second);
 	}
 }
 
