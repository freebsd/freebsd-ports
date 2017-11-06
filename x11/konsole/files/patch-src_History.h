* Change to 64bit types for scrollback fixes in History.cpp
*
--- src/History.h.orig	2014-11-01 04:17:02 UTC
+++ src/History.h
@@ -46,9 +46,9 @@ public:
     HistoryFile();
     virtual ~HistoryFile();
 
-    virtual void add(const unsigned char* bytes, int len);
-    virtual void get(unsigned char* bytes, int len, int loc);
-    virtual int  len() const;
+    virtual void add(const char* bytes, qint64 len);
+    virtual void get(char* bytes, qint64 len, qint64 loc);
+    virtual qint64 len() const;
 
     //mmaps the file in read-only mode
     void map();
@@ -59,12 +59,11 @@ public:
 
 
 private:
-    int  _fd;
-    int  _length;
+    qint64  _length;
     QTemporaryFile _tmpFile;
 
     //pointer to start of mmap'ed file data, or 0 if the file is not mmap'ed
-    char* _fileMap;
+    uchar* _fileMap;
 
     //incremented whenever 'add' is called and decremented whenever
     //'get' is called.
@@ -139,9 +138,9 @@ public:
     virtual void addLine(bool previousWrapped = false);
 
 private:
-    int startOfLine(int lineno);
+    qint64 startOfLine(int lineno);
 
-    HistoryFile _index; // lines Row(int)
+    HistoryFile _index; // lines Row(qint64)
     HistoryFile _cells; // text  Row(Character)
     HistoryFile _lineflags; // flags Row(unsigned char)
 };
