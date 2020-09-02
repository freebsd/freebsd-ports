--- draw.h.orig	2019-06-25 12:55:46 UTC
+++ draw.h
@@ -96,4 +96,4 @@ void eprintf(const char *fmt, ...);
 void weprintf(const char *fmt, ...);
 int32_t round_to_int(double val);
 
-const char *progname;
+extern const char *progname;
