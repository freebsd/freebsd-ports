--- system.mk.orig	Sat Jun 25 17:13:43 2005
+++ system.mk	Sat Jul 16 18:56:28 2005
@@ -7,7 +7,7 @@
 ## Installation paths
 ##
 
-PREFIX=/usr/local
+#PREFIX=/usr/local
 
 # Unless you are creating a package conforming to some OS's standards, you
 # probably do not want to modify the following directories:
@@ -19,7 +19,7 @@
 # Some .lua files and ion-* shell scripts
 SHAREDIR=$(PREFIX)/share/ion3
 # Manual pages
-MANDIR=$(PREFIX)/share/man
+MANDIR=$(MANPREFIX)/man
 # Some documents
 DOCDIR=$(PREFIX)/share/doc/ion3
 # Nothing at the moment
@@ -47,7 +47,7 @@
 #PRELOAD_MODULES=1
 
 # Flags to link with libdl.
-DL_LIBS=-ldl
+#DL_LIBS=-ldl
 
 
 ##
@@ -56,7 +56,7 @@
 
 # If you have installed Lua 5.0 from the official tarball without changing
 # paths, this should do it.
-LUA_DIR=/usr/local
+LUA_DIR=$(LOCALBASE)
 LUA_LIBS = -L$(LUA_DIR)/lib -llua -llualib
 LUA_INCLUDES = -I$(LUA_DIR)/include
 LUA=$(LUA_DIR)/bin/lua
@@ -74,7 +74,7 @@
 ## X libraries, includes and options
 ##
 
-X11_PREFIX=/usr/X11R6
+X11_PREFIX=$(X11BASE)
 # SunOS/Solaris
 #X11_PREFIX=/usr/openwin
 
@@ -107,7 +107,7 @@
 # asprintf and vasprintf in the c library. (gnu libc has.)
 # If HAS_SYSTEM_ASPRINTF is not defined, an implementation
 # in sprintf_2.2/ is used.
-#HAS_SYSTEM_ASPRINTF=1
+HAS_SYSTEM_ASPRINTF=1
 
 
 # If you're on an archaic system (such as relatively recent *BSD releases)
@@ -116,24 +116,24 @@
 #DEFINES += -DCF_NO_LOCALE
 
 # On some other systems you may something like this:
-#EXTRA_LIBS += -lintl
-#EXTRA_INCLUDES +=
+EXTRA_LIBS += -L$(LOCALBASE)/lib -lintl
+EXTRA_INCLUDES += -I$(LOCALBASE)/include
 
 
 ##
 ## C compiler
 ##
 
-CC=gcc
+CC?=gcc
 
 # Same as '-Wall -pedantic' without '-Wunused' as callbacks often
 # have unused variables.
 WARN=	-W -Wimplicit -Wreturn-type -Wswitch -Wcomment \
 	-Wtrigraphs -Wformat -Wchar-subscripts \
-	-Wparentheses -pedantic -Wuninitialized
+	-Wparentheses
 
-CFLAGS=-g -Os $(WARN) $(DEFINES) $(EXTRA_INCLUDES) $(INCLUDES)
-LDFLAGS=-g -Os $(EXTRA_LIBS) $(LIBS)
+CFLAGS=$(WARN) $(DEFINES) $(EXTRA_INCLUDES) $(INCLUDES)
+LDFLAGS=$(EXTRA_LIBS) $(LIBS)
 EXPORT_DYNAMIC=-Xlinker --export-dynamic
 
 # The following options are mainly for development use and can be used
@@ -147,7 +147,7 @@
 #POSIX_SOURCE=-D_POSIX_SOURCE
 
 # Most systems
-#XOPEN_SOURCE=-D_XOPEN_SOURCE -D_XOPEN_SOURCE_EXTENDED
+XOPEN_SOURCE=-D_XOPEN_SOURCE -D_XOPEN_SOURCE_EXTENDED
 # SunOS, (Irix)
 #XOPEN_SOURCE=-D__EXTENSIONS__
 
