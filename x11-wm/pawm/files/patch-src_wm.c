$FreeBSD$

Make ANSI C89/C90-compliant to compile with GCC 2.X.
author:  Volker Stolz

--- src/wm.c.orig	Wed Apr 14 16:32:24 2004
+++ src/wm.c	Wed Apr 14 16:32:44 2004
@@ -311,8 +311,8 @@
 
     char *tmpvalue;
 
-    SAY ("Initializing window manager...");
     int (*olderrorhandler) (Display *, XErrorEvent *);
+    SAY ("Initializing window manager...");
 
     if (reference_count++) return !0;
  
