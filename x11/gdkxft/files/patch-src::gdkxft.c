
$FreeBSD$

--- src/gdkxft.c.orig	Sat Sep  1 19:00:02 2001
+++ src/gdkxft.c	Mon Sep  3 18:34:29 2001
@@ -20,7 +20,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <regex.h>
+#include <gnuregex.h>
 
 #include <X11/Xlib.h>
 #include <X11/Xos.h>
@@ -170,7 +170,7 @@
   else if(!access(SYSCONFDIR "/gdkxft.conf",R_OK)) 
     read_cfg_file(SYSCONFDIR "/gdkxft.conf",xfre,ftre);
   else 
-    read_cfg_file(DATADIR "/gdkxft.conf",xfre,ftre);
+    read_cfg_file(DATADIR "/gdkxft/gdkxft.conf",xfre,ftre);
 
   /* compile regexps */
   g_string_append_c(xfre,'$');
