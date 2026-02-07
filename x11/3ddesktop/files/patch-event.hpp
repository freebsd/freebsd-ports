--- event.hpp.orig	2004-12-06 02:57:32 UTC
+++ event.hpp
@@ -74,7 +74,7 @@ class EventManager { (public)
         list<Event *>::iterator k;
         for (k = events.begin(); k != events.end(); ++k) {
             Event *e = *k;
-            printf(":: Event %d  0x%x\n", e->type, (unsigned int)(e->function));
+            printf(":: Event %d  %p\n", e->type, e->function);
         }
     }
 
