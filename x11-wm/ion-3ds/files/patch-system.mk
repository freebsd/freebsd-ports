--- system.mk.orig	Sun Mar 18 21:32:12 2007
+++ system.mk	Sat Mar 31 22:49:58 2007
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
@@ -56,11 +56,11 @@
 
 # If you have installed Lua 5.1 from the official tarball without changing
 # paths, this should do it.
-LUA_DIR=/usr/local
-LUA_LIBS = -L$(LUA_DIR)/lib -llua
-LUA_INCLUDES = -I$(LUA_DIR)/include
-LUA=$(LUA_DIR)/bin/lua
-LUAC=$(LUA_DIR)/bin/luac
+LUA_DIR=$(LOCALBASE)
+LUA_LIBS = -L$(LUA_LIBDIR) -llua
+LUA_INCLUDES = -I$(LUA_INCDIR)
+LUA=$(LUA_BINDIR)/lua
+LUAC=$(LUA_BINDIR)/luac
 
 # If you are using the Debian packages, the following settings should be
 # what you want.
@@ -74,7 +74,7 @@
 ## X libraries, includes and options
 ##
 
-X11_PREFIX=/usr/X11R6
+X11_PREFIX=$(X11BASE)
 # SunOS/Solaris
 #X11_PREFIX=/usr/openwin
 
@@ -83,7 +83,7 @@
 
 # XFree86 libraries up to 4.3.0 have a bug that can cause a segfault.
 # The following setting  should  work around that situation.
-DEFINES += -DCF_XFREE86_TEXTPROP_BUG_WORKAROUND
+#DEFINES += -DCF_XFREE86_TEXTPROP_BUG_WORKAROUND
 
 # Use the Xutf8 routines (XFree86 extension) instead of the Xmb routines
 # in an UTF-8 locale. (No, you don't need this in UTF-8 locales, and 
@@ -104,7 +104,7 @@
 # asprintf and vasprintf in the c library. (gnu libc has.)
 # If HAS_SYSTEM_ASPRINTF is not defined, an implementation
 # in sprintf_2.2/ is used.
-#HAS_SYSTEM_ASPRINTF=1
+HAS_SYSTEM_ASPRINTF=1
 
 # If you're on an archaic system (such as relatively recent *BSD releases)
 # without even dummy multibyte/widechar and localisation support, you may 
@@ -112,24 +112,24 @@
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
+CFLAGS+=$(WARN) $(DEFINES) $(EXTRA_INCLUDES) $(INCLUDES)
+LDFLAGS+=$(EXTRA_LIBS) $(LIBS)
 EXPORT_DYNAMIC=-Xlinker --export-dynamic
 
 # The following options are mainly for development use and can be used
@@ -143,7 +143,7 @@
 #POSIX_SOURCE=-D_POSIX_SOURCE
 
 # Most systems
-#XOPEN_SOURCE=-D_XOPEN_SOURCE -D_XOPEN_SOURCE_EXTENDED
+XOPEN_SOURCE=-D_XOPEN_SOURCE -D_XOPEN_SOURCE_EXTENDED
 # SunOS, (Irix)
 #XOPEN_SOURCE=-D__EXTENSIONS__
 
