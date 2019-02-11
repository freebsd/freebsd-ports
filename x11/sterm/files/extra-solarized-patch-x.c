--- x.c.orig	2019-02-09 12:50:41.000000000 +0100
+++ x.c	2019-02-11 14:02:22.026884000 +0100
@@ -53,6 +53,7 @@
 static void clippaste(const Arg *);
 static void numlock(const Arg *);
 static void selpaste(const Arg *);
+static void swapcolors(const Arg *);
 static void zoom(const Arg *);
 static void zoomabs(const Arg *);
 static void zoomreset(const Arg *);
@@ -240,6 +241,8 @@
 
 static int oldbutton = 3; /* button event on startup: 3 = release */
 
+int usealtcolors = 0; /* 1 to use alternate palette */
+
 void
 clipcopy(const Arg *dummy)
 {
@@ -279,6 +282,14 @@
 }
 
 void
+swapcolors(const Arg *dummy)
+{
+	usealtcolors = !usealtcolors;
+	xloadcols();
+	redraw();
+}
+
+void
 zoom(const Arg *arg)
 {
 	Arg larg;
@@ -702,6 +713,11 @@
 	return x == 0 ? 0 : 0x3737 + 0x2828 * x;
 }
 
+const char* getcolorname(int i)
+{
+    return (usealtcolors) ?  altcolorname[i] : colorname[i];
+}
+
 int
 xloadcolor(int i, const char *name, Color *ncolor)
 {
@@ -720,7 +736,7 @@
 			return XftColorAllocValue(xw.dpy, xw.vis,
 			                          xw.cmap, &color, ncolor);
 		} else
-			name = colorname[i];
+			name = getcolorname(i);
 	}
 
 	return XftColorAllocName(xw.dpy, xw.vis, xw.cmap, name, ncolor);
@@ -737,14 +753,14 @@
 		for (cp = dc.col; cp < &dc.col[dc.collen]; ++cp)
 			XftColorFree(xw.dpy, xw.vis, xw.cmap, cp);
 	} else {
-		dc.collen = MAX(LEN(colorname), 256);
+		dc.collen = MAX(LEN(colorname), LEN(altcolorname));
 		dc.col = xmalloc(dc.collen * sizeof(Color));
 	}
 
 	for (i = 0; i < dc.collen; i++)
 		if (!xloadcolor(i, NULL, &dc.col[i])) {
-			if (colorname[i])
-				die("could not allocate color '%s'\n", colorname[i]);
+			if (getcolorname(i))
+				die("could not allocate color '%s'\n", getcolorname(i));
 			else
 				die("could not allocate color %d\n", i);
 		}
@@ -1082,13 +1098,13 @@
 	cursor = XCreateFontCursor(xw.dpy, mouseshape);
 	XDefineCursor(xw.dpy, xw.win, cursor);
 
-	if (XParseColor(xw.dpy, xw.cmap, colorname[mousefg], &xmousefg) == 0) {
+	if (XParseColor(xw.dpy, xw.cmap, getcolorname(mousefg), &xmousefg) == 0) {
 		xmousefg.red   = 0xffff;
 		xmousefg.green = 0xffff;
 		xmousefg.blue  = 0xffff;
 	}
 
-	if (XParseColor(xw.dpy, xw.cmap, colorname[mousebg], &xmousebg) == 0) {
+	if (XParseColor(xw.dpy, xw.cmap, getcolorname(mousebg), &xmousebg) == 0) {
 		xmousebg.red   = 0x0000;
 		xmousebg.green = 0x0000;
 		xmousebg.blue  = 0x0000;
@@ -1298,7 +1314,7 @@
 
 	/* Change basic system colors [0-7] to bright system colors [8-15] */
 	if ((base.mode & ATTR_BOLD_FAINT) == ATTR_BOLD && BETWEEN(base.fg, 0, 7))
-		fg = &dc.col[base.fg + 8];
+		fg = &dc.col[base.fg];
 
 	if (IS_SET(MODE_REVERSE)) {
 		if (fg == &dc.col[defaultfg]) {
