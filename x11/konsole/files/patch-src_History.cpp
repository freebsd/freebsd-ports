* Revamp the file-based "unlimited" scrollback code to remove limits
* caused by 32bit file offsets. Use Qt's I/O functions which are
* buffered and use 64bit offsets. Use Qt's map instead of direct mmap
* to ensure consistency. Prevent wrap-around of readWriteBalance.
*
--- src/History.cpp.orig	2014-11-01 04:17:02 UTC
+++ src/History.cpp
@@ -25,9 +25,6 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <sys/types.h>
-#include <sys/mman.h>
-#include <unistd.h>
-#include <errno.h>
 
 // KDE
 #include <kde_file.h>
@@ -56,8 +53,7 @@ using namespace Konsole;
 
 // History File ///////////////////////////////////////////
 HistoryFile::HistoryFile()
-    : _fd(-1),
-      _length(0),
+    : _length(0),
       _fileMap(0),
       _readWriteBalance(0)
 {
@@ -66,7 +62,6 @@ HistoryFile::HistoryFile()
     _tmpFile.setFileTemplate(tmpFormat);
     if (_tmpFile.open()) {
         _tmpFile.setAutoRemove(true);
-        _fd = _tmpFile.handle();
     }
 }
 
@@ -83,23 +78,26 @@ void HistoryFile::map()
 {
     Q_ASSERT(_fileMap == 0);
 
-    _fileMap = (char*)mmap(0 , _length , PROT_READ , MAP_PRIVATE , _fd , 0);
+    if (_tmpFile.flush()) {
+        Q_ASSERT(_tmpFile.size() >= _length);
+        _fileMap = _tmpFile.map(0, _length);
+	}
 
     //if mmap'ing fails, fall back to the read-lseek combination
-    if (_fileMap == MAP_FAILED) {
+    if (_fileMap == 0) {
         _readWriteBalance = 0;
-        _fileMap = 0;
-        kWarning() << "mmap'ing history failed.  errno = " << errno;
+        perror("HistoryFile::map failed");
     }
 }
 
 void HistoryFile::unmap()
 {
-    int result = munmap(_fileMap , _length);
-    Q_ASSERT(result == 0);
-    Q_UNUSED(result);
+    Q_ASSERT(_fileMap != 0);
 
-    _fileMap = 0;
+    if (_tmpFile.unmap(_fileMap))
+        _fileMap = 0;
+
+    Q_ASSERT(_fileMap == 0);
 }
 
 bool HistoryFile::isMapped() const
@@ -107,21 +105,21 @@ bool HistoryFile::isMapped() const
     return (_fileMap != 0);
 }
 
-void HistoryFile::add(const unsigned char* buffer, int count)
+void HistoryFile::add(const char* buffer, qint64 count)
 {
     if (_fileMap)
         unmap();
 
-    _readWriteBalance++;
+    if (_readWriteBalance < INT_MAX)
+        _readWriteBalance++;
 
-    int rc = 0;
+    qint64 rc = 0;
 
-    rc = KDE_lseek(_fd, _length, SEEK_SET);
-    if (rc < 0) {
+    if (!_tmpFile.seek(_length)) {
         perror("HistoryFile::add.seek");
         return;
     }
-    rc = write(_fd, buffer, count);
+    rc = _tmpFile.write(buffer, count);
     if (rc < 0) {
         perror("HistoryFile::add.write");
         return;
@@ -129,30 +127,32 @@ void HistoryFile::add(const unsigned cha
     _length += rc;
 }
 
-void HistoryFile::get(unsigned char* buffer, int size, int loc)
+void HistoryFile::get(char* buffer, qint64 size, qint64 loc)
 {
+     if (loc < 0 || size < 0 || loc + size > _length) {
+        fprintf(stderr, "getHist(...,%lld,%lld): invalid args.\n", size, loc);
+        return;
+    }
+
     //count number of get() calls vs. number of add() calls.
     //If there are many more get() calls compared with add()
     //calls (decided by using MAP_THRESHOLD) then mmap the log
     //file to improve performance.
-    _readWriteBalance--;
+    if (_readWriteBalance > INT_MIN)
+        _readWriteBalance--;
     if (!_fileMap && _readWriteBalance < MAP_THRESHOLD)
         map();
 
     if (_fileMap) {
-        for (int i = 0; i < size; i++)
-            buffer[i] = _fileMap[loc + i];
+        memcpy(buffer, _fileMap + loc, size);
     } else {
-        int rc = 0;
+        qint64 rc = 0;
 
-        if (loc < 0 || size < 0 || loc + size > _length)
-            fprintf(stderr, "getHist(...,%d,%d): invalid args.\n", size, loc);
-        rc = KDE_lseek(_fd, loc, SEEK_SET);
-        if (rc < 0) {
+        if (!_tmpFile.seek(loc)) {
             perror("HistoryFile::get.seek");
             return;
         }
-        rc = read(_fd, buffer, size);
+        rc = _tmpFile.read(buffer, size);
         if (rc < 0) {
             perror("HistoryFile::get.read");
             return;
@@ -160,7 +160,7 @@ void HistoryFile::get(unsigned char* buf
     }
 }
 
-int HistoryFile::len() const
+qint64 HistoryFile::len() const
 {
     return _length;
 }
@@ -206,7 +206,7 @@ HistoryScrollFile::~HistoryScrollFile()
 
 int HistoryScrollFile::getLines()
 {
-    return _index.len() / sizeof(int);
+    return _index.len() / sizeof(qint64);
 }
 
 int HistoryScrollFile::getLineLen(int lineno)
@@ -218,21 +218,18 @@ bool HistoryScrollFile::isWrappedLine(in
 {
     if (lineno >= 0 && lineno <= getLines()) {
         unsigned char flag;
-        _lineflags.get((unsigned char*)&flag, sizeof(unsigned char), (lineno)*sizeof(unsigned char));
+        _lineflags.get((char*)&flag, sizeof(unsigned char), (lineno)*sizeof(unsigned char));
         return flag;
     }
     return false;
 }
 
-int HistoryScrollFile::startOfLine(int lineno)
+qint64 HistoryScrollFile::startOfLine(int lineno)
 {
     if (lineno <= 0) return 0;
     if (lineno <= getLines()) {
-        if (!_index.isMapped())
-            _index.map();
-
-        int res;
-        _index.get((unsigned char*)&res, sizeof(int), (lineno - 1)*sizeof(int));
+        qint64 res;
+        _index.get((char*)&res, sizeof(qint64), (lineno - 1)*sizeof(qint64));
         return res;
     }
     return _cells.len();
@@ -240,23 +237,20 @@ int HistoryScrollFile::startOfLine(int l
 
 void HistoryScrollFile::getCells(int lineno, int colno, int count, Character res[])
 {
-    _cells.get((unsigned char*)res, count * sizeof(Character), startOfLine(lineno) + colno * sizeof(Character));
+    _cells.get((char*)res, count * sizeof(Character), startOfLine(lineno) + colno * sizeof(Character));
 }
 
 void HistoryScrollFile::addCells(const Character text[], int count)
 {
-    _cells.add((unsigned char*)text, count * sizeof(Character));
+    _cells.add((char*)text, count * sizeof(Character));
 }
 
 void HistoryScrollFile::addLine(bool previousWrapped)
 {
-    if (_index.isMapped())
-        _index.unmap();
-
-    int locn = _cells.len();
-    _index.add((unsigned char*)&locn, sizeof(int));
+    qint64 locn = _cells.len();
+    _index.add((char*)&locn, sizeof(qint64));
     unsigned char flags = previousWrapped ? 0x01 : 0x00;
-    _lineflags.add((unsigned char*)&flags, sizeof(unsigned char));
+    _lineflags.add((char*)&flags, sizeof(unsigned char));
 }
 
 // History Scroll None //////////////////////////////////////
