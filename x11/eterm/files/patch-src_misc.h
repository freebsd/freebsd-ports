
$FreeBSD$

--- src/misc.h.orig
+++ src/misc.h
@@ -40,6 +40,7 @@
 extern unsigned long str_leading_match(register const char *, register const char *);
 extern char *str_trim(char *str);
 extern int parse_escaped_string(char *str);
+extern spif_charptr_t escape_string(spif_charptr_t str, spif_char_t quote, spif_int32_t maxlen);
 extern char *safe_print_string(const char *buff, unsigned long len);
 extern unsigned long add_carriage_returns(unsigned char *buff, unsigned long cnt);
 extern unsigned char mkdirhier(const char *);
