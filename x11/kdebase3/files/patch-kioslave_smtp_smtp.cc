Index: kioslave/smtp/smtp.cc
diff -u kioslave/smtp/smtp.cc.orig kioslave/smtp/smtp.cc
--- kioslave/smtp/smtp.cc.orig	2007-10-08 18:51:22.000000000 +0900
+++ kioslave/smtp/smtp.cc	2012-12-12 15:29:29.604353297 +0900
@@ -31,6 +31,7 @@
 #include <config.h>
 
 #ifdef HAVE_LIBSASL2
+#include <sys/types.h>
 extern "C" {
 #include <sasl/sasl.h>
 }
