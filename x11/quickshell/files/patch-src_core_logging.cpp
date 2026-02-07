--- src/core/logging.cpp.orig	2025-10-12 00:14:14 UTC
+++ src/core/logging.cpp
@@ -27,7 +27,16 @@
 #include <qtmetamacros.h>
 #include <qtypes.h>
 #include <sys/mman.h>
+#if defined(__linux__)
 #include <sys/sendfile.h>
+#else
+#include <unistd.h>
+#include <sys/types.h>
+#if defined(__NetBSD__) || defined(__DragonFly__)
+#include <sys/socket.h>
+#include <sys/uio.h>
+#endif
+#endif
 
 #include "instanceinfo.hpp"
 #include "logcat.hpp"
@@ -389,7 +398,7 @@ void ThreadLogging::initFs() {
 		delete detailedFile;
 		detailedFile = nullptr;
 	} else {
-		auto lock = flock {
+		struct flock lock {
 		    .l_type = F_WRLCK,
 		    .l_whence = SEEK_SET,
 		    .l_start = 0,
@@ -411,7 +420,19 @@ void ThreadLogging::initFs() {
 		auto* oldFile = this->file;
 		if (oldFile) {
 			oldFile->seek(0);
+#if defined(__linux__)
 			sendfile(file->handle(), oldFile->handle(), nullptr, oldFile->size());
+#elif defined(__FreeBSD__)
+			copy_file_range(oldFile->handle(), nullptr, file->handle(), nullptr, oldFile->size(), 0);
+#elif defined(__NetBSD__) || defined(__DragonFly__)
+			sendfile(oldFile->handle(), file->handle(), 0, oldFile->size(), nullptr, nullptr, 0);
+#elif defined(__OpenBSD__)
+			constexpr size_t BUF_SIZE = 1 << 20;
+			char buf[BUF_SIZE];
+			ssize_t r = read(oldFile->handle(), buf, oldFile->size() > BUF_SIZE ? BUF_SIZE : (size_t)oldFile->size());
+			if (r > 0)
+				write(file->handle(), buf, r);
+#endif
 		}
 
 		this->file = file;
@@ -423,7 +444,19 @@ void ThreadLogging::initFs() {
 		auto* oldFile = this->detailedFile;
 		if (oldFile) {
 			oldFile->seek(0);
+#if defined(__linux__)
 			sendfile(detailedFile->handle(), oldFile->handle(), nullptr, oldFile->size());
+#elif defined(__FreeBSD__)
+			copy_file_range(oldFile->handle(), nullptr, detailedFile->handle(), nullptr, oldFile->size(), 0);
+#elif defined(__NetBSD__) || defined(__DragonFly__)
+			sendfile(oldFile->handle(), detailedFile->handle(), 0, oldFile->size(), nullptr, nullptr, 0);
+#elif defined(__OpenBSD__)
+			constexpr size_t BUF_SIZE = 1 << 20;
+			char buf[BUF_SIZE];
+			ssize_t r = read(oldFile->handle(), buf, oldFile->size() > BUF_SIZE ? BUF_SIZE : (size_t)oldFile->size());
+			if (r > 0)
+				write(detailedFile->handle(), buf, r);
+#endif
 		}
 
 		crash::CrashInfo::INSTANCE.logFd = detailedFile->handle();
@@ -886,7 +919,7 @@ void LogFollower::FcntlWaitThread::run() {
 }
 
 void LogFollower::FcntlWaitThread::run() {
-	auto lock = flock {
+	struct flock lock {
 	    .l_type = F_RDLCK, // won't block other read locks when we take it
 	    .l_whence = SEEK_SET,
 	    .l_start = 0,
