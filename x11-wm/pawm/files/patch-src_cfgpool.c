$FreeBSD$

FreeBSD 4 is not C99-compliant.

--- src/cfgpool.c.orig	Wed Aug  6 14:27:17 2003
+++ src/cfgpool.c	Sat Oct 18 17:18:40 2003
@@ -309,13 +309,13 @@ legal value*. So, for proper error check
     EINVAL: Couldn't parse a well-formed natural number.
     ERANGE: Overflow while parsing the number.
 */
-uintmax_t
+u_int32_t
 cfgpool_getnatural (CfgPool pool, const char *key, unsigned int base) {
 
     char *value=NULL;
     char *tailptr=NULL;
     int tmperrno=errno;
-    uintmax_t natural=0;
+    u_int32_t natural=0;
 
     ASSERT(pool);
     ASSERT(key);
@@ -329,7 +329,7 @@ cfgpool_getnatural (CfgPool pool, const 
 
     /* Well, it seems we have a value... Translate to correct type */
     errno=0;
-    natural=strtoumax(value, &tailptr, base);
+    natural=strtoull(value, &tailptr, base);
     
     if (errno) natural=0,tmperrno=ERANGE;
     if ((!natural) && (tailptr==value)) tmperrno=EINVAL;
@@ -359,13 +359,13 @@ legal value*. So, for proper error check
     ERANGE: Overflow while parsing the number.
 */
 
-intmax_t
+u_int32_t
 cfgpool_getinteger (CfgPool pool, const char *key, unsigned int base) {
 
     char *value=NULL;
     char *tailptr=NULL;
     int tmperrno=errno;
-    intmax_t integer=0;
+    u_int32_t integer=0;
 
     ASSERT(pool);
     ASSERT(key);
@@ -379,7 +379,7 @@ cfgpool_getinteger (CfgPool pool, const 
 
     /* Well, it seems we have a value... Translate to correct type */
     errno=0;
-    integer=strtoimax(value, &tailptr, base);
+    integer=strtoll(value, &tailptr, base);
     
     if (errno) integer=0,tmperrno=ERANGE;
     if ((!integer) && (tailptr==value)) tmperrno=EINVAL;
