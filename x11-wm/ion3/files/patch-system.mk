--- system.mk.orig	Tue Jun  1 16:35:23 2004
+++ system.mk	Sat Jun  5 13:27:08 2004
@@ -7,7 +7,7 @@
 ## Installation paths
 ##
 
-PREFIX=/usr/local
+#PREFIX=/usr/local
 
 # Unless you are creating a package conforming to some OS's standards, you
 # probably do not want to modify the following directories:
@@ -19,7 +19,7 @@
 # Some .lua files and ion-* shell scripts
 SHAREDIR=$(PREFIX)/share/ion
 # Manual pages
-MANDIR=$(PREFIX)/share/man
+MANDIR=$(PREFIX)/man
 # Some documents
 DOCDIR=$(PREFIX)/share/doc/ion
 # Nothing at the moment
@@ -42,11 +42,11 @@
 # libtool because even more-recent-than-libtool-1.4.3 releases of those
 # OSes only have an _ancient_ 1.3.x libtool that _will_ _not_ _work even
 # though a lot of libltdl-using apps require 1.4.3.
-LIBTOOL=libtool
+LIBTOOL=$(LOCALBASE)/bin/libtool15 --tag=CC
 
 # Settings for compiling and linking to ltdl
-LTDL_INCLUDES=
-LTDL_LIBS=-lltdl
+LTDL_INCLUDES=-I$(LOCALBASE)/include
+LTDL_LIBS=-L$(LOCALBASE)/lib -lltdl
 
 # The following should do it if you have manually installed libtool 1.5 in
 # $(LIBTOOLDIR).
@@ -72,7 +72,7 @@
 
 # If you have installed Lua 5.0 from the official tarball without changing
 # paths, this should do it.
-LUA_DIR=/usr/local
+LUA_DIR=$(LOCALBASE)
 LUA_LIBS = -L$(LUA_DIR)/lib -R$(LUA_DIR)/lib -llua -llualib
 LUA_INCLUDES = -I$(LUA_DIR)/include
 LUA=$(LUA_DIR)/bin/lua
@@ -90,7 +90,7 @@
 ## X libraries, includes and options
 ##
 
-X11_PREFIX=/usr/X11R6
+X11_PREFIX=$(X11BASE)
 # SunOS/Solaris
 #X11_PREFIX=/usr/openwin
 
@@ -119,7 +119,7 @@
 # asprintf and vasprintf in the c library. (gnu libc has.)
 # If HAS_SYSTEM_ASPRINTF is not defined, an implementation
 # in sprintf_2.2/ is used.
-#HAS_SYSTEM_ASPRINTF=1
+HAS_SYSTEM_ASPRINTF=1
 
 
 # If you're on an archaic system (such as relatively recent *BSD releases)
@@ -132,16 +132,16 @@
 ## C compiler
 ##
 
-CC=gcc
+CC?=gcc
 
 # Same as '-Wall -pedantic' without '-Wunused' as callbacks often
 # have unused variables.
 WARN=	-W -Wimplicit -Wreturn-type -Wswitch -Wcomment \
 	-Wtrigraphs -Wformat -Wchar-subscripts \
-	-Wparentheses -pedantic -Wuninitialized
+	-Wparentheses -Wuninitialized
 
-CFLAGS=-g -Os $(WARN) $(DEFINES) $(EXTRA_INCLUDES) $(INCLUDES)
-LDFLAGS=-g -Os $(EXTRA_LIBS) $(LIBS)
+CFLAGS+= $(WARN) $(DEFINES) $(EXTRA_INCLUDES) $(INCLUDES)
+LDFLAGS= $(EXTRA_LIBS) $(LIBS)
 
 # The following options are mainly for development use and can be used
 # to check that the code seems to conform to some standards. Depending
@@ -154,7 +154,7 @@
 #POSIX_SOURCE=-D_POSIX_SOURCE
 
 # Most systems
-#XOPEN_SOURCE=-D_XOPEN_SOURCE -D_XOPEN_SOURCE_EXTENDED
+XOPEN_SOURCE=-D_XOPEN_SOURCE -D_XOPEN_SOURCE_EXTENDED
 # SunOS, (Irix)
 #XOPEN_SOURCE=-D__EXTENSIONS__
 
