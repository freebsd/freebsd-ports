--- acinclude.m4.orig	2017-08-27 19:29:50.000000000 -0700
+++ acinclude.m4	2023-12-04 15:48:12.951361000 -0800
@@ -50,7 +50,12 @@
 AC_DEFUN([AM_FUNC_VOID_SPRINTF],
 [AC_CACHE_CHECK(whether sprintf returns void, ac_cv_func_void_sprintf,
 [AC_TRY_RUN([#include <stdio.h>
-int sprintf(); main() { exit(sprintf(".")); }],
+int main() {
+  char buf[1];
+  int i = sprintf(buf, "");
+  return 0;
+}
+],
   ac_cv_func_void_sprintf=no, ac_cv_func_void_sprintf=yes, ac_cv_func_void_sprintf=yes)])
 if test $ac_cv_func_void_sprintf = no; then
   AC_DEFINE(VOID_SPRINTF,1,
