--- ./kio/kfile/kdiskfreespaceinfo.cpp.orig	2010-02-26 21:30:10.000000000 +0300
+++ ./kio/kfile/kdiskfreespaceinfo.cpp	2010-04-11 23:48:30.795826504 +0400
@@ -133,7 +133,7 @@
     // Prefer mountPoint if available, so that it even works with non-existing files.
     const QString pathArg = info.d->mountPoint.isEmpty() ? path : info.d->mountPoint;
     if (!statvfs(QFile::encodeName(pathArg).constData(), &statvfs_buf)) {
-        const quint64 blksize = quint64(statvfs_buf.f_bsize); // cast to avoid overflow
+        const quint64 blksize = quint64(statvfs_buf.f_frsize); // cast to avoid overflow
         info.d->available = statvfs_buf.f_bavail * blksize;
         info.d->size = statvfs_buf.f_blocks * blksize;
         info.d->valid = true;
