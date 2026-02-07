--- src/crispy/read_selector.h.orig	2026-01-06 17:41:07 UTC
+++ src/crispy/read_selector.h
@@ -107,7 +107,7 @@ class posix_read_selector
         if (timeout.has_value())
         {
             tv = std::make_unique<timeval>(
-                timeval { .tv_sec = timeout->count() / 1000,
+                timeval { .tv_sec = static_cast<int>(timeout->count() / 1000),
                           .tv_usec = static_cast<int>((timeout->count() % 1000) * 1000) });
         }
 
