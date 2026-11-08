-- Qt6 changed QList's size type from int to qsizetype and made several
-- accessor methods const-overloaded.  The PythonQt generator inherits these
-- signatures for any instantiations of QList (e.g. QPolygon, QPolygonF,
-- QItemSelection), but the generated wrappers return them as QChar pointers
-- because the template parsing resolves the value type incorrectly.  Remove
-- the problematic QList accessors entirely so that the generated code compiles.

--- generator/typesystem.cpp.orig	2026-09-15 09:14:25 UTC
+++ generator/typesystem.cpp
@@ -2098,6 +2098,14 @@
   removeFunction(qlist, "last()");
   removeFunction(qlist, "operator[](int)");
   removeFunction(qlist, "operator[](int) const");
+  removeFunction(qlist, "operator[](qsizetype)");
+  removeFunction(qlist, "operator[](qsizetype) const");
+  removeFunction(qlist, "at(int) const");
+  removeFunction(qlist, "at(qsizetype) const");
+  removeFunction(qlist, "back() const");
+  removeFunction(qlist, "front() const");
+  removeFunction(qlist, "takeFirst()");
+  removeFunction(qlist, "takeLast()");
   removeFunction(qlist, "operator=(QList<T>)");

   ContainerTypeEntry* qqueue = db->findContainerType(QLatin1String("QQueue"));
