--- system.mk.orig	Thu Dec 28 21:42:07 2000
+++ system.mk	Sun Jan 21 05:24:15 2001
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
@@ -23,7 +23,7 @@
 ## X libraries, includes and options
 ##
 
-X11_PREFIX=/usr/X11R6
+X11_PREFIX=$(X11BASE)
 
 # SunOS/Solaris
 #X11_PREFIX=/usr/openwin
@@ -78,8 +78,8 @@
 	-Wparentheses -pedantic-errors -Wuninitialized
 
 
-CFLAGS=-g -O2 $(WARN) $(DEFINES) $(INCLUDES) $(EXTRA_INCLUDES)
-LDFLAGS=-g $(LIBS) $(EXTRA_LIBS)
+CFLAGS+= $(WARN) $(DEFINES) $(INCLUDES) $(EXTRA_INCLUDES)
+LDFLAGS= $(LIBS) $(EXTRA_LIBS)
 
 
 ##
@@ -104,9 +104,9 @@
 ##
 
 # Should work almost everywhere
-INSTALL=install
+#INSTALL=install
 # On a system with pure BSD install, -c might be preferred
-#INSTALL=install -c
+INSTALL=install -c
 
 INSTALLDIR=mkdir -p
