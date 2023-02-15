--- lib/DtSearch/raima/connect.c.orig	2023-02-14 21:59:59.313528000 -0800
+++ lib/DtSearch/raima/connect.c	2023-02-14 22:08:01.746583000 -0800
@@ -84,8 +84,8 @@
    char *orec;            /* ptr to current owner record contents in cache */
    char *mrec;            /* ptr to current member record contents in cache */
    char *nrec;            /* ptr to next member record contents in cache */
-   DB_ADDR mdba = NULL;   /* db address of current member record */
-   DB_ADDR ndba = NULL;   /* db address of next member record */
+   DB_ADDR mdba = 0;      /* db address of current member record */
+   DB_ADDR ndba = 0;      /* db address of next member record */
    INT ordering;          /* set order control variable */
    int stat, compare;     /* status code & sort comparison result */
    SET_ENTRY *set_ptr;
