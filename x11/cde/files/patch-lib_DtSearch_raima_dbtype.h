Remove unnecessary and conflicting global variable

--- lib/DtSearch/raima/dbtype.h.orig	2021-02-11 09:26:30.733694000 +0000
+++ lib/DtSearch/raima/dbtype.h	2021-02-11 09:25:05.275302000 +0000
@@ -405,7 +405,7 @@
 struct sk {
    INT sk_fld;
    CHAR_P sk_val;
-} __SK__;
+};
 typedef struct { struct sk *ptr; LOCK_DESC } SK_P;
 
 /* node key search path stack entry: one per level per key field */
