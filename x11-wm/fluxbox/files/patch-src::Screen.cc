--- src/Screen.cc.orig	Thu Feb 28 10:46:01 2002
+++ src/Screen.cc	Tue Mar 12 16:48:03 2002
@@ -877,8 +877,9 @@
 	Netizens::iterator it_end = netizenList.end();
 	for (; it != it_end; ++it) {
 		if ((*it)->getWindowID() == w) {
-			Netizen *n = *netizenList.erase(it);
+			Netizen *n = *it;
 			delete n;
+			netizenList.erase(it);			
 			break;
 		}
 	}
