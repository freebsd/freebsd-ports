--- cmd/wmii/event.c.orig	2020-10-18 09:39:16 UTC
+++ cmd/wmii/event.c
@@ -5,6 +5,8 @@
 #include <X11/keysym.h>
 #include "fns.h"
 
+long	ignoreenter;
+
 typedef void (*EvHandler)(XEvent*);
 
 void
