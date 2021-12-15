--- programs/dtinfo/DtMmdb/storage/spointer.h.orig	2021-12-14 10:42:39 UTC
+++ programs/dtinfo/DtMmdb/storage/spointer.h
@@ -52,7 +52,7 @@
 
 struct header_t 
 {
-#ifdef MMDB_BIG_ENDIAN
+#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
    unsigned spointer    : 14;
    unsigned length      : 14;
    unsigned is_object   : 1;
