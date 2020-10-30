--- src/PositionCache.h.orig	2020-07-18 05:40:22 UTC
+++ src/PositionCache.h
@@ -187,8 +187,8 @@ class PositionCacheEntry { (public)
 	PositionCacheEntry() noexcept;
 	// Copy constructor not currently used, but needed for being element in std::vector.
 	PositionCacheEntry(const PositionCacheEntry &);
+	PositionCacheEntry(PositionCacheEntry &&) noexcept = default;
 	// Deleted so PositionCacheEntry objects can not be assigned.
-	PositionCacheEntry(PositionCacheEntry &&) = delete;
 	void operator=(const PositionCacheEntry &) = delete;
 	void operator=(PositionCacheEntry &&) = delete;
 	~PositionCacheEntry();
