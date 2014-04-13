$FreeBSD$

--- libAfterBase/parse.h.orig	2014-04-12 10:22:23.000000000 -0700
+++ libAfterBase/parse.h	2014-04-11 06:31:10.000000000 -0700
@@ -73,7 +73,7 @@
 
 double parse_math(const char* str, char** endptr, double size);
 
-inline int unsigned_int2buffer_end (char *buffer, int buffer_size, unsigned int val);
+int unsigned_int2buffer_end (char *buffer, int buffer_size, unsigned int val);
 char *string_from_int (int param);
 char *hex_to_buffer_reverse(void *data, size_t bytes, char* buffer);
 char *hex_to_buffer(void *data, size_t bytes, char* buffer);
