--- programs/dtinfo/DtMmdb/utility/atoi_pearson.C.orig	2021-12-14 01:08:51 UTC
+++ programs/dtinfo/DtMmdb/utility/atoi_pearson.C
@@ -107,14 +107,14 @@ atoi_pearson::~atoi_pearson()
 }
 
 struct reg_t {
-#ifdef MMDB_BIG_ENDIAN
+#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
    unsigned b4: 8;
    unsigned b3: 8;
    unsigned b2: 8;
    unsigned b1: 8;
 #endif
 
-#ifdef MMDB_LITTLE_ENDIAN
+#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    unsigned b1: 8;
    unsigned b2: 8;
    unsigned b3: 8;
