--- libs/taskmanager/task.cpp.orig	2018-08-30 10:05:33 UTC
+++ libs/taskmanager/task.cpp
@@ -478,10 +478,10 @@ bool Task::idMatch(const QString& id1, c
     if (id1.isEmpty() || id2.isEmpty())
         return false;
 
-    if (id1.contains(id2) > 0)
+    if (id1.contains(id2))
         return true;
 
-    if (id2.contains(id1) > 0)
+    if (id2.contains(id1))
         return true;
 
     return false;
