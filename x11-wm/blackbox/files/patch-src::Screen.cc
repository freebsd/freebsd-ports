--- src/Screen.cc.orig	Wed Sep  4 19:15:58 2002
+++ src/Screen.cc	Thu Sep 19 09:12:24 2002
@@ -1120,7 +1120,7 @@
       focused->getScreen()->getScreenNumber() == getScreenNumber() &&
       current_workspace->getCount() > 1) {
     do {
-      next = current_workspace->getNextWindowInList(next);
+      next = current_workspace->getPrevWindowInList(next);
     } while(next != focused && ! next->setInputFocus());
 
     if (next != focused)
