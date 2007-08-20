--- linkedlist.cc.orig	2001-11-03 12:14:01.000000000 -0500
+++ linkedlist.cc	2007-08-13 11:19:56.000000000 -0400
@@ -131,7 +131,7 @@
 	// looking for.
 	if(temp == NULL) 
 	{
-		cerr << "_LinkedList::remove : element not found" << endl;
+		std::cerr << "_LinkedList::remove : element not found" << std::endl;
 		return;
 	
 	} else {
@@ -172,7 +172,7 @@
 		
 		reset(direction);
 	} else {
-		cerr << "_LinkedListIterator: List is NULL" << endl;
+		std::cerr << "_LinkedListIterator: List is NULL" << std::endl;
 		exit(-1);
 	}
 }	
@@ -192,7 +192,7 @@
 		break;
 			
 		default:
-			cerr << "_LinkedListIterator: Illegal direction for list traversal using FORWARD" << endl;
+			std::cerr << "_LinkedListIterator: Illegal direction for list traversal using FORWARD" << std::endl;
 			list->setForward();
 			element = list->head;
 		break;
