--- ./pekwm/Observable.hh.orig	2012-05-18 12:51:49.000000000 +0000
+++ ./pekwm/Observable.hh	2014-01-05 16:56:43.000000000 +0000
@@ -9,11 +9,7 @@
 #ifndef _OBSERVABLE_HH_
 #define _OBSERVABLE_HH_
 
-#ifdef HAVE_SLIST
-#include <slist>
-#else // HAVE_EXT_SLIST
-#include <ext/slist>
-#endif // HAVE_SLIST
+#include <vector>
 
 class Observer;
 
@@ -36,7 +32,7 @@
     void removeObserver(Observer *observer); 
 
 private:
-    SLIST_NAMESPACE::slist<Observer*> _observers; /**< List of observers. */
+    std::vector<Observer*> _observers; /**< List of observers. */
 };
 
 #endif // _OBSERVABLE_HH_
