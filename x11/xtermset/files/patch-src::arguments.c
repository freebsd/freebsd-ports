--- src/arguments.c	2000/12/20 15:54:27	1.2
+++ src/arguments.c	2001/04/14 16:21:52
@@ -62,8 +62,9 @@
    current = first;
 
    while(current!=NULL) {
+      argument *next = current->next;
       free(current);
-      current=current->next;
+      current = next;
    }
 
    current = NULL;
