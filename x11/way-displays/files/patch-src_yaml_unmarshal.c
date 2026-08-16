src/yaml/unmarshal.c:72:28: error: call to undeclared function 'basename'; ISO C99 and later do not support implicit function declarations [-Werror,-Wimplicit-function-declaration]
   72 |         yaml_unmarshal_log_prefix(basename(tmp));
      |                                   ^
src/yaml/unmarshal.c:72:28: error: incompatible integer to pointer conversion passing 'int' to parameter of type 'const char *' [-Wint-conversion]
   72 |         yaml_unmarshal_log_prefix(basename(tmp));
      |                                   ^~~~~~~~~~~~~
inc/yaml/unmarshal.h:45:51: note: passing argument to parameter 'prefix' here
   45 | void yaml_unmarshal_log_prefix       (const char *prefix);    // message prefix
      |                                                   ^

--- src/yaml/unmarshal.c.orig	2026-08-16 23:02:16 UTC
+++ src/yaml/unmarshal.c
@@ -1,3 +1,4 @@
+#include <libgen.h>
 #include <stdbool.h>
 #include <stdio.h>
 #include <stdlib.h>
