--- lib/libxview/ttysw/cim_size.c.orig	2005-03-28 06:41:31.000000000 -0800
+++ lib/libxview/ttysw/cim_size.c	2012-02-03 11:32:42.637883645 -0800
@@ -156,7 +156,7 @@
 {
 
     if (lines_ptr) {
-#ifndef __CYGWIN__
+#if !defined(__CYGWIN__) && !defined(__FreeBSD__)
         cfree((CHAR *) (lines_ptr));
 #else
         free((CHAR *) (lines_ptr));
@@ -164,7 +164,7 @@
 	lines_ptr = NULL;
     }
     if (image) {
-#ifndef __CYGWIN__
+#if !defined(__CYGWIN__) && !defined(__FreeBSD__)
         cfree((CHAR **) image);
 #else
         free((CHAR **) image);
@@ -172,7 +172,7 @@
 	image = NULL;
     }
     if (mode_ptr) {
-#ifndef __CYGWIN__
+#if !defined(__CYGWIN__) && !defined(__FreeBSD__)
 	cfree((char *) (mode_ptr));
 #else
         free((char *) (mode_ptr));
@@ -180,7 +180,7 @@
 	mode_ptr = NULL;
     }
     if (screenmode) {
-#ifndef __CYGWIN__
+#if !defined(__CYGWIN__) && !defined(__FreeBSD__)
 	cfree((char **) screenmode);
 #else
         free((char **) screenmode);
