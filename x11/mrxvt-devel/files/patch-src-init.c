Index: src/init.c
===================================================================
--- src/init.c	(revision 195)
+++ src/init.c	(working copy)
@@ -41,7 +41,7 @@
 # define DEBUG_X
 #else
 # define DEBUG_LEVEL	0
-# define DEBUG_X
+# undef DEBUG_X
 #endif
 
 #if DEBUG_LEVEL
