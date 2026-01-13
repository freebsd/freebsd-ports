--- src/core/toolsupport.cpp.orig	2025-10-12 00:14:14 UTC
+++ src/core/toolsupport.cpp
@@ -54,7 +54,7 @@ bool QmlToolingSupport::lockTooling() {
 		return false;
 	}
 
-	auto lock = flock {
+	struct flock lock {
 	    .l_type = F_WRLCK,
 	    .l_whence = SEEK_SET, // NOLINT (fcntl.h??)
 	    .l_start = 0,
