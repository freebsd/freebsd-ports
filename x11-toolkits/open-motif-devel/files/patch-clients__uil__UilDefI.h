--- clients/uil/UilDefI.h.orig	2012-10-22 07:50:39.000000000 -0700
+++ clients/uil/UilDefI.h	2012-10-26 15:18:31.064731493 -0700
@@ -270,7 +270,7 @@
 #include "UilIODef.h"
 #include "UilDiagDef.h"
 #include "UilSarDef.h"
-#if defined(linux) || defined(__APPLE__)
+#if defined(linux) || defined(__APPLE__) || defined(__FreeBSD__)
 #define YYSTYPE yystype
 #endif
 #include "UilLexPars.h"
