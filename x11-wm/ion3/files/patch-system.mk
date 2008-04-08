--- system.mk.orig	2008-02-05 12:42:06.000000000 -0500
+++ system.mk	2008-04-08 00:14:27.000000000 -0400
@@ -8,7 +8,7 @@
 
 # Installation path prefix. Unless you know what you're doing, the default
 # of /usr/local is likely the correct choice.
-PREFIX=/usr/local
+#PREFIX=/usr/local
 
 # Unless you are creating a package conforming to some OS's standards, you
 # probably do not want to modify the following directories:
@@ -20,7 +20,7 @@
 # Some .lua files and ion-* shell scripts
 SHAREDIR=$(PREFIX)/share/ion3
 # Manual pages
-MANDIR=$(PREFIX)/share/man
+MANDIR=$(PREFIX)/man
 # Some documents
 DOCDIR=$(PREFIX)/share/doc/ion3
 # Nothing at the moment
@@ -53,7 +53,7 @@
 
 # Flags to link with libdl. Even if PRELOAD_MODULES=1, you may need this
 # setting (for e.g. Lua, when not instructed by pkg-config).
-DL_LIBS=-ldl
+#DL_LIBS=-ldl
 
 
 ##
@@ -62,11 +62,11 @@
 
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
@@ -81,7 +81,7 @@
 ##
 
 # Paths
-X11_PREFIX=/usr/X11R6
+X11_PREFIX=$(X11BASE)
 # SunOS/Solaris
 #X11_PREFIX=/usr/openwin
 
@@ -90,7 +90,7 @@
 
 # XFree86 libraries up to 4.3.0 have a bug that can cause a segfault.
 # The following setting  should  work around that situation.
-DEFINES += -DCF_XFREE86_TEXTPROP_BUG_WORKAROUND
+#DEFINES += -DCF_XFREE86_TEXTPROP_BUG_WORKAROUND
 
 # Use the Xutf8 routines (XFree86 extension) instead of the Xmb routines
 # in an UTF-8 locale. (No, you don't need this in UTF-8 locales, and 
@@ -113,12 +113,14 @@
 #DEFINES += -DCF_NO_LOCALE -DCF_NO_GETTEXT
 
 # On some other systems you may need to explicitly link against libintl.
-#EXTRA_LIBS += -lintl
+EXTRA_LIBS += -lintl
 # You may also need to give the location of its headers. The following
 # should work on Mac OS X (which needs the above option as well) with
 # macports.
 #EXTRA_INCLUDES += -I/opt/local/include
 
+EXTRA_INCLUDES+=	-I$(LOCALBASE)/include $(PORT_CFLAGS)
+EXTRA_LIBS+=	-L$(LOCALBASE)/lib
 
 ##
 ## libc
@@ -127,7 +129,7 @@
 # You may uncomment this if you know that your system C libary provides
 # asprintf and  vasprintf. (GNU libc does.) If HAS_SYSTEM_ASPRINTF is not
 # defined, an implementation provided in libtu/sprintf_2.2/ is used. 
-#HAS_SYSTEM_ASPRINTF=1
+HAS_SYSTEM_ASPRINTF=1
 
 # The following setting is needed with GNU libc for clock_gettime and the
 # monotonic clock. Other systems may not need it, or may not provide a
@@ -149,15 +151,15 @@
 ## C compiler. 
 ##
 
-CC=gcc
+CC?=gcc
 
 # Same as '-Wall -pedantic' without '-Wunused' as callbacks often
 # have unused variables.
 WARN=	-W -Wimplicit -Wreturn-type -Wswitch -Wcomment \
 	-Wtrigraphs -Wformat -Wchar-subscripts \
-	-Wparentheses -pedantic -Wuninitialized
+	-Wparentheses
 
-CFLAGS=-Os $(WARN) $(DEFINES) $(INCLUDES) $(EXTRA_INCLUDES)
+CFLAGS= $(WARN) $(DEFINES) $(INCLUDES) $(EXTRA_INCLUDES)
 LDFLAGS=$(LIBS) $(EXTRA_LIBS)
 EXPORT_DYNAMIC=-Xlinker --export-dynamic
 
@@ -172,7 +174,7 @@
 #POSIX_SOURCE=-D_POSIX_C_SOURCE=200112L
 
 # Most systems
-#XOPEN_SOURCE=-D_XOPEN_SOURCE -D_XOPEN_SOURCE_EXTENDED
+XOPEN_SOURCE=-D_XOPEN_SOURCE -D_XOPEN_SOURCE_EXTENDED
 # SunOS, (Irix)
 #XOPEN_SOURCE=-D__EXTENSIONS__
 
