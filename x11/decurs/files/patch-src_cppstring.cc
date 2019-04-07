--- src/cppstring.cc.orig	2019-04-05 11:08:03 UTC
+++ src/cppstring.cc
@@ -4,6 +4,7 @@
 #include "cppstring.hh"
 #include "idefs.h"
 #include <iostream>
+#include <stdarg.h>
 // #include <except.h>
 #define DEF_BUFFER_SIZE     512
 #define CPPSTRING_ERROR(obj,msg,retval) {obj<<"*** ERROR *** : "<<msg<<std::endl;return retval;}
