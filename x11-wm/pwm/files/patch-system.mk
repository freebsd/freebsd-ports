--- system.mk.orig	Sat Sep 28 18:57:23 2002
+++ system.mk	Sat Sep 28 18:57:31 2002
@@ -55,7 +55,7 @@
 # have unused variables.
 WARN=	-W -Wimplicit -Wreturn-type -Wswitch -Wcomment \
 	-Wtrigraphs -Wformat -Wchar-subscripts -Wuninitialized \
-	-Wparentheses -pedantic-errors
+	-Wparentheses
 
 CFLAGS=-g -O2 $(WARN) $(DEFINES) $(INCLUDES) $(EXTRA_INCLUDES)
 LDFLAGS=-g $(LIBS) $(EXTRA_LIBS)
