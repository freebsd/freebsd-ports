--- src/core/paths.cpp.orig	2025-10-12 00:14:14 UTC
+++ src/core/paths.cpp
@@ -346,7 +346,7 @@ void QsPaths::createLock() {
 			return;
 		}
 
-		auto lock = flock {
+		struct flock lock {
 		    .l_type = F_WRLCK,
 		    .l_whence = SEEK_SET,
 		    .l_start = 0,
@@ -373,7 +373,7 @@ bool QsPaths::checkLock(const QString& path, InstanceL
 	auto file = QFile(QDir(path).filePath("instance.lock"));
 	if (!file.open(QFile::ReadOnly)) return false;
 
-	auto lock = flock {
+	struct flock lock {
 	    .l_type = F_WRLCK,
 	    .l_whence = SEEK_SET,
 	    .l_start = 0,
