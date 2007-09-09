Index: src/xdefaults.c
===================================================================
--- src/xdefaults.c	(revision 244)
+++ src/xdefaults.c	(working copy)
@@ -203,8 +203,6 @@
 	    "scroll-on-tty-output inhibit" ),
     BOOL( "scrollTtyKeypress", "sk", Opt_scrollTtyKeypress,
 	    "scroll-on-keypress" ),
-    BOOL( "scrollWithBuffer", "sw", Opt_scrollWithBuffer,
-	    "scroll-with-buffer" ),
 
     STRG(Rs_opacity, "opacity", "o", "%",
 	"transluscent window (true transparent) opaque degree", 0),
