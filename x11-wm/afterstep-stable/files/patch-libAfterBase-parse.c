$FreeBSD$

--- libAfterBase/parse.c.orig	2014-04-12 10:22:32.000000000 -0700
+++ libAfterBase/parse.c	2014-04-11 06:31:13.000000000 -0700
@@ -1027,7 +1027,7 @@
 
 static char _as_hex_to_char_table[] = "0123456789ABCDEF";
 
-inline int
+int
 unsigned_int2buffer_end (char *buffer, int buffer_size, unsigned int val)
 {
 	int i = buffer_size-1 ; 
