diff -ur generic/shape.c shape0.4.new/generic/shape.c.new
--- generic/shape.c	Mon Sep 11 17:16:31 2000
+++ generic/shape.c.new	Fri Jan 30 15:20:15 2004
@@ -25,7 +25,6 @@
 #include <tkInt.h>
 #endif
 #include <X11/Xutil.h>
-#include "panic.h"
 
 #define min(x,y) ((x)<(y)?(x):(y))
 #define max(x,y) ((x)<(y)?(y):(x))
@@ -38,6 +37,10 @@
      _ANSI_ARGS_((Tk_Window tkwin, Tcl_Interp *interp, int x, int y, int op,
 		  int kind, int objc, Tcl_Obj *CONST objv[]));
 
+static Tk_Window getWindow(Tk_Window, Tcl_Interp*, Tcl_Obj*, int *);
+
+int Shape_Init(Tcl_Interp *);
+
 static int
 shapeBoundClipOps _ANSI_ARGS_((Tk_Window tkwin, Tcl_Interp *interp, int opnum,
 			       int objc, Tcl_Obj *CONST objv[]));
@@ -76,7 +79,7 @@
 enum {
   boundsCmd, getCmd, offsetCmd, setCmd, updateCmd, versionCmd
 };
-static char *subcommands[] = {
+static CONST char *subcommands[] = {
   "bounds", "get", "offset", "set", "update", "version", NULL
 };
 static shapeCommandHandler shapeCommandHandlers[] = {
@@ -133,7 +136,7 @@
      int opnum, objc;
      Tcl_Obj *CONST objv[];
 {
-    static char *options[] = {
+    static CONST char *options[] = {
 	"-bounding", "-clip", NULL
     };
     int idx = 0,toplevel;
@@ -160,7 +163,7 @@
 	    return TCL_ERROR;
 	}
 	if (valid) {
-	    Tcl_Obj *r, *result[4];
+		Tcl_Obj /* *r, */ *result[4];
 
 	    result[0] = Tcl_NewIntObj(x1);
 	    result[1] = Tcl_NewIntObj(y1);
@@ -178,6 +181,8 @@
     default: /* should be impossible to get here! */
 	panic("unexpected operation number %d", opnum);
     }
+    
+    return TCL_OK;
 }
 
 static int
@@ -187,12 +192,14 @@
      int opnum, objc;
      Tcl_Obj *CONST objv[];
 {
-    static char *opts[] = {
+    static CONST char *opts[] = {
 	"-bounding", "-clip", "-both", NULL
     };
     int x,y,toplevel, i = SHAPE_KIND_BOTH-1;
     Tk_Window tkwin;
 
+    opnum = 0;	/* unused */
+
     /* Argument parsing */
     switch (objc) {
     default:
@@ -256,6 +263,8 @@
     XRectangle *rects;
     int count,i,result;
 
+    x = y = op = 0;	/* unused */
+
     if (objc != 1) {
 	Tcl_AppendResult(interp, "rectangles requires one argument; "
 			 "a list of rectangles", NULL);
@@ -309,6 +318,10 @@
      int x, y, op, kind, objc;
      Tcl_Obj *CONST objv[];
 {
+
+	x = y = op;	/* unused */
+	objv = NULL;	/* unused */
+
     if (objc != 0) {
 	Tcl_AppendResult(interp, "reset takes no arguments", NULL);
 	return TCL_ERROR;
@@ -327,6 +340,8 @@
     XRectangle *rects;
     int count, result;
 
+    x = y;	/* unused */
+
     if (objc != 2) {
 	Tcl_AppendResult(interp, "text requires two arguments; the string "
 			 "to display and the font to use to display it",
@@ -356,8 +371,7 @@
      Tcl_Obj *CONST objv[];
 {
     Tk_Window srcwin;
-    int ignore, result;
-    Display *dpy;
+    int ignore;
 
     if (objc != 1) {
 	Tcl_AppendResult(interp, "window requires one argument; a window "
@@ -388,7 +402,7 @@
 	return TCL_ERROR;
     }
 
-    imageName = Tcl_GetStringFromObj(objv[0], &NULL);
+    imageName = Tcl_GetStringFromObj(objv[0], NULL);
     handle = Tk_FindPhoto(interp, imageName);
     if (handle == NULL) {
 	return TCL_ERROR;
@@ -418,19 +432,19 @@
     enum optkind {
 	shapekind, offsetargs, sourceargs
     };
-    static char *options[] = {
+    static CONST char *options[] = {
 	"-offset",
 	"-bounding", "-clip", "-both",
 	"bitmap", "rectangles", "reset", "text", "window",
 #ifdef SUPPORTS_PHOTO_REGION
-	"photo"
+	"photo",
 #endif
 	NULL
     };
     static enum optkind optk[] = {
 	offsetargs,
 	shapekind, shapekind, shapekind,
-	sourceargs, sourceargs, sourceargs, sourceargs, sourceargs
+	sourceargs, sourceargs, sourceargs, sourceargs, sourceargs,
 #ifdef SUPPORTS_PHOTO_REGION
 	sourceargs
 #endif
@@ -458,7 +472,7 @@
 	idx = 3;
 	break;
     case updateCmd: {
-	static char *operations[] = {
+	static CONST char *operations[] = {
 	    "set", "union", "intersect", "subtract", "invert",
 	    ":=", "+=", "*=", "-=", "=", "||", "&&", NULL
 	};
@@ -570,6 +584,8 @@
     default: /* should be impossible to get here! */
 	panic("switch fallthrough");
     }
+
+    return TCL_OK;
 }
 
 int
