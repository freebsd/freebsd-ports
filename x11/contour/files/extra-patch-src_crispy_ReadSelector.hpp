--- src/crispy/ReadSelector.hpp.orig	2026-08-19 07:00:03 UTC
+++ src/crispy/ReadSelector.hpp
@@ -131,7 +131,7 @@ class PosixReadSelector
         if (timeout.has_value())
         {
             tv = std::make_unique<timeval>(
-                timeval { .tv_sec = timeout->count() / 1000,
+                timeval { .tv_sec = static_cast<time_t>(timeout->count() / 1000),
                           .tv_usec = static_cast<int>((timeout->count() % 1000) * 1000) });
         }
 
