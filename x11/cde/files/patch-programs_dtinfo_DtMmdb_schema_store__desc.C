--- programs/dtinfo/DtMmdb/schema/store_desc.C.orig	2021-12-14 19:59:51 UTC
+++ programs/dtinfo/DtMmdb/schema/store_desc.C
@@ -66,11 +66,11 @@ store_desc::store_desc(const char* name) : desc(name)
    mode_str = strdup("");
    order_str = 0;
 
-#ifdef MMDB_BIG_ENDIAN
+#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
    order_str = strdup("big_endian");
 #endif
 
-#ifdef MMDB_LITTLE_ENDIAN
+#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    order_str = strdup("little_endian");
 #endif
 
@@ -87,11 +87,11 @@ store_desc::store_desc(int tp, const char* comment): 
 
    order_str = 0;
 
-#ifdef MMDB_BIG_ENDIAN
+#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
    order_str = strdup("big_endian");
 #endif
 
-#ifdef MMDB_LITTLE_ENDIAN
+#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    order_str = strdup("little_endian");
 #endif
 
