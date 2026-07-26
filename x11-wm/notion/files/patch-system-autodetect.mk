Apply llvm22 fix from OpenBSD port by commenting
POSIX_SOURCE and XOPEN_SOURCE.
fda9c504296741 ("update to notion-4.0.5, unbreaking build with llvm22")

--- system-autodetect.mk.orig	2026-04-21 20:44:17 UTC
+++ system-autodetect.mk
@@ -138,6 +138,7 @@ HAS_SYSTEM_ASPRINTF=1
 
 # On some other systems you may something like this:
 #LIBS += -L/usr/local/lib -lintl
+LIBS += -L$(LOCALBASE)/lib -lintl
 #CPPFLAGS += -I/usr/local/include
 
 
@@ -195,11 +196,11 @@ EXPORT_DYNAMIC=-Xlinker --export-dynamic
 
 #C89_SOURCE=-ansi
 
-POSIX_SOURCE?=-D_POSIX_C_SOURCE=200112L
+#POSIX_SOURCE?=-D_POSIX_C_SOURCE=200112L
 BSD_SOURCE?=-D_BSD_SOURCE
 
 # Most systems
-XOPEN_SOURCE=-D_XOPEN_SOURCE -D_XOPEN_SOURCE_EXTENDED
+#XOPEN_SOURCE=-D_XOPEN_SOURCE -D_XOPEN_SOURCE_EXTENDED
 # SunOS, (Irix)
 #XOPEN_SOURCE=-D__EXTENSIONS__
 
