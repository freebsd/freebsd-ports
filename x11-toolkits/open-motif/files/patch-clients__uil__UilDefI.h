--- clients/uil/UilDefI.h.orig	2017-12-05 12:46:16 UTC
+++ clients/uil/UilDefI.h
@@ -263,7 +263,7 @@ extern char* uil_mmove(char*, char*, int);
 #include "UilIODef.h"
 #include "UilDiagDef.h"
 #include "UilSarDef.h"
-#if defined(linux) || defined(__APPLE__)
+#if defined(linux) || defined(__APPLE__) || defined(__FreeBSD__)
 #define YYSTYPE yystype
 #endif
 #include "UilLexPars.h"
