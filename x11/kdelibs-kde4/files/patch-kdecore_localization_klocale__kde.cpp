contains() returns bool or QBool, and clang7 picks the an
overload that casts to void *, and then fails on the ordered
comparison. Drop the strange comparison instead.

--- kdecore/localization/klocale_kde.cpp.orig	2018-08-23 20:23:08 UTC
+++ kdecore/localization/klocale_kde.cpp
@@ -2438,8 +2438,8 @@ QString KLocalePrivate::formatLocaleTime
 
 bool KLocalePrivate::use12Clock() const
 {
-    if ((timeFormat().contains(QString::fromLatin1("%I")) > 0) ||
-        (timeFormat().contains(QString::fromLatin1("%l")) > 0)) {
+    if (bool(timeFormat().contains(QString::fromLatin1("%I"))) ||
+        bool(timeFormat().contains(QString::fromLatin1("%l")))) {
         return true;
     } else {
         return false;
