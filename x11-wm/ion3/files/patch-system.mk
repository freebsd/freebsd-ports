--- system.mk.orig	Sat Jan 19 18:15:13 2002
+++ system.mk	Sat Sep  7 15:53:15 2002
@@ -7,13 +7,13 @@
 ## Installation paths
 ##
 
-PREFIX=/usr/local
+#PREFIX=/usr/local
 
 # No need to modify these usually
 BINDIR=$(PREFIX)/bin
 ETCDIR=$(PREFIX)/etc
 MANDIR=$(PREFIX)/man
-DOCDIR=$(PREFIX)/doc
+DOCDIR=$(PREFIX)/share/doc
 # Not used
 INCDIR=$(PREFIX)/include
 LIBDIR=$(PREFIX)/lib
@@ -24,14 +24,14 @@
 ##
 
 #MODULE_SUPPORT=-DCF_NO_MODULE_SUPPORT
-MODULE_SUPPORT_LDFLAGS=-export-dynamic -ldl
+MODULE_SUPPORT_LDFLAGS=-export-dynamic
 
 
 ##
 ## X libraries, includes and options
 ##
 
-X11_PREFIX=/usr/X11R6
+X11_PREFIX=$(X11BASE)
 
 # SunOS/Solaris
 #X11_PREFIX=/usr/openwin
@@ -83,11 +83,11 @@
 # have unused variables.
 WARN=	-W -Wimplicit -Wreturn-type -Wswitch -Wcomment \
 	-Wtrigraphs -Wformat -Wchar-subscripts \
-	-Wparentheses -pedantic-errors -Wuninitialized
+	-Wparentheses -Wuninitialized
 
 
-CFLAGS=-g -O2 $(WARN) $(DEFINES) $(INCLUDES) $(EXTRA_INCLUDES)
-LDFLAGS=-g $(LIBS) $(EXTRA_LIBS)
+CFLAGS+= $(WARN) $(DEFINES) $(INCLUDES) $(EXTRA_INCLUDES)
+LDFLAGS= $(LIBS) $(EXTRA_LIBS)
 
 
 ##
@@ -112,9 +112,9 @@
 ##
 
 # Should work almost everywhere
-INSTALL=install
+#INSTALL=install
 # On a system with pure BSD install, -c might be preferred
-#INSTALL=install -c
+INSTALL=install -c
 
 INSTALLDIR=mkdir -p
 
