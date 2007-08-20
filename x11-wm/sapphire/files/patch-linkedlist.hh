--- linkedlist.hh.orig	2001-11-03 12:17:15.000000000 -0500
+++ linkedlist.hh	2007-08-13 10:45:53.000000000 -0400
@@ -42,8 +42,8 @@
 	// I wanna make the next,prev, and data pointers private.
 	// But I still need LinkedList and LinkedListIterator
 	// to access those pointers.
-	friend _LinkedList;
-	friend _LinkedListIterator;
+	friend class _LinkedList;
+	friend class _LinkedListIterator;
 
 private: // Variables 
 	
@@ -67,7 +67,7 @@
 	Element *head, *tail, *iter;
 	int elements;
 
-	friend _LinkedListIterator;
+	friend class _LinkedListIterator;
 
 private: // Member functions 
 	
@@ -160,4 +160,4 @@
 	T* current() { return (T*) _LinkedListIterator::current(); }
 };
 
-#endif
\ No newline at end of file
+#endif
