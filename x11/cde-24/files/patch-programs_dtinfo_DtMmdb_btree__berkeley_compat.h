--- programs/dtinfo/DtMmdb/btree_berkeley/compat.h.orig	2021-12-14 13:35:18 UTC
+++ programs/dtinfo/DtMmdb/btree_berkeley/compat.h
@@ -147,11 +147,11 @@ void * __fix_realloc __P((void*, size_t));
 #define LITTLE_ENDIAN	1234		/* LSB first: i386, vax */
 #define BIG_ENDIAN	4321		/* MSB first: 68000, ibm, net */
 
-#ifdef MMDB_LITTLE_ENDIAN
+#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
 #define BYTE_ORDER	LITTLE_ENDIAN	/* Set for your system. */
 #endif
 
-#ifdef MMDB_BIG_ENDIAN
+#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
 #define BYTE_ORDER	BIG_ENDIAN	/* Set for your system. */
 #endif
 
