--- ./kdecore/util/kshareddatacache_p.h.orig	2011-10-28 05:24:56.297083311 -0700
+++ ./kdecore/util/kshareddatacache_p.h	2011-10-28 05:25:42.467076066 -0700
@@ -423,9 +423,6 @@
 #ifdef __GNUC__
 #warning "This system does not seem to support posix_fallocate, which is needed to ensure KSharedDataCache's underlying files are fully committed to disk to avoid crashes with low disk space."
 #endif
-    kWarning(ksdcArea()) << "This system misses support for posix_fallocate()"
-                            " -- ensure this partition has room for at least"
-                         << fileSize << "bytes.";
 
     // TODO: It's possible to emulate the functionality, but doing so
     // overwrites the data in the file so we don't do this. If you were to add
