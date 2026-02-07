--- system-autodetect.mk.orig	2025-02-08 16:04:21 UTC
+++ system-autodetect.mk
@@ -138,6 +138,7 @@ HAS_SYSTEM_ASPRINTF=1
 
 # On some other systems you may something like this:
 #LIBS += -L/usr/local/lib -lintl
+LIBS += -L$(LOCALBASE)/lib -lintl
 #CPPFLAGS += -I/usr/local/include
 
 
