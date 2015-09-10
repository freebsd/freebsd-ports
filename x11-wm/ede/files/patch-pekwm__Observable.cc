--- pekwm/Observable.cc.orig	2014-06-21 21:24:41 UTC
+++ pekwm/Observable.cc
@@ -10,10 +10,12 @@
 #include "config.h"
 #endif // HAVE_CONFIG_H
 
+#include <algorithm>
+
 #include "Observable.hh"
 #include "Observer.hh"
 
-using SLIST_NAMESPACE::slist;
+using std::vector;
 
 /**
  * Notify all observers.
@@ -21,11 +23,10 @@ using SLIST_NAMESPACE::slist;
 void
 Observable::notifyObservers(Observation *observation)
 {
-    if (_observers.size()) {
-        slist<Observer*>::iterator it(_observers.begin());
-        for (; it != _observers.end(); ++it) {
-            (*it)->notify(this, observation);
-        }
+    vector<Observer*>::const_iterator it(_observers.begin());
+    vector<Observer*>::const_iterator end(_observers.end());
+    for (; it != end; ++it) {
+        (*it)->notify(this, observation);
     }
 }
 
@@ -35,7 +36,7 @@ Observable::notifyObservers(Observation 
 void
 Observable::addObserver(Observer *observer)
 {
-    _observers.push_front(observer);
+    _observers.push_back(observer);
 }
 
 /**
@@ -44,7 +45,5 @@ Observable::addObserver(Observer *observ
 void
 Observable::removeObserver(Observer *observer)
 {
-    if (_observers.size()) {
-        _observers.remove(observer);
-    }
+    _observers.erase(std::remove(_observers.begin(), _observers.end(), observer), _observers.end());
 }
