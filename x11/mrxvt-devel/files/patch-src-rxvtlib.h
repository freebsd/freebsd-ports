Index: src/rxvtlib.h
===================================================================
--- src/rxvtlib.h	(revision 244)
+++ src/rxvtlib.h	(working copy)
@@ -280,7 +280,7 @@
 #define Opt_forceTransparent	    ((1LU<<16) | IS_OPTION1)
 #define Opt_mc_hack		    ((1LU<<17) | IS_OPTION1)
 #define Opt_tripleclickwords	    ((1LU<<18) | IS_OPTION1)
-#define Opt_scrollWithBuffer	    ((1LU<<19) | IS_OPTION1)
+/* #define Opt_scrollWithBuffer	    ((1LU<<19) | IS_OPTION1) */
 #define Opt_mouseWheelScrollPage    ((1LU<<21) | IS_OPTION1)
 #define Opt_pointerBlank	    ((1LU<<22) | IS_OPTION1)
 #define Opt_cursorBlink		    ((1LU<<23) | IS_OPTION1)
Index: src/xdefaults.c
