--- clients/uil/UilDefI.h.orig	2011-01-16 01:16:45.000000000 +0300
+++ clients/uil/UilDefI.h	2011-01-16 01:17:35.000000000 +0300
@@ -283,7 +283,7 @@
 #include "UilIODef.h"
 #include "UilDiagDef.h"
 #include "UilSarDef.h"
-#if defined(linux)
+#if defined(linux) || defined(__FreeBSD__)
 #define YYSTYPE yystype
 #endif
 #include "UilLexPars.h"
