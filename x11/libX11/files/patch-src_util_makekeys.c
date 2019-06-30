--- src/util/makekeys.c.orig	2019-06-17 14:47:35 UTC
+++ src/util/makekeys.c
@@ -35,8 +35,10 @@ from The Open Group.
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <stdint.h>
+#include <inttypes.h>
 
-#include "../Xresinternal.h"
+typedef uint32_t Signature;
 
 #define KTNUM 4000
 
