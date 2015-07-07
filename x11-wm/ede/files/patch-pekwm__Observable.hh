--- pekwm/Observable.hh.orig	2014-06-21 21:24:41 UTC
+++ pekwm/Observable.hh
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
 
@@ -36,7 +32,7 @@ public:
     void removeObserver(Observer *observer); 
 
 private:
-    SLIST_NAMESPACE::slist<Observer*> _observers; /**< List of observers. */
+    std::vector<Observer*> _observers; /**< List of observers. */
 };
 
 #endif // _OBSERVABLE_HH_
