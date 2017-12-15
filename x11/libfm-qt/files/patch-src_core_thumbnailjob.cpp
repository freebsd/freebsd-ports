--- src/core/thumbnailjob.cpp.orig	2017-10-21 18:56:43 UTC
+++ src/core/thumbnailjob.cpp
@@ -83,7 +83,12 @@ QImage ThumbnailJob::loadForFile(const s
     // calculate md5 hash for the uri of the original file
     g_checksum_update(md5Calc_, reinterpret_cast<const unsigned char*>(uri.get()), -1);
     memcpy(thumbnailName, g_checksum_get_string(md5Calc_), 32);
+#if defined(Q_OS_LINUX)
     mempcpy(thumbnailName + 32, ".png", 5);
+#else
+    memcpy(thumbnailName + 32, ".png", 5);
+    thumbnailName + 5;
+#endif
     g_checksum_reset(md5Calc_); // reset the checksum calculator for next use
 
     QString thumbnailFilename = thumbnailDir;
