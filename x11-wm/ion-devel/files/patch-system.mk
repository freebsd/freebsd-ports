--- system.mk.orig	Mon Mar  5 09:16:01 2001
+++ system.mk	Thu Mar 29 11:37:26 2001
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
@@ -86,8 +86,8 @@
 	-Wparentheses -pedantic-errors -Wuninitialized
 
 
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
 
