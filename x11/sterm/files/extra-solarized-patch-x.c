--- x.c.orig	2018-03-20 20:29:59 UTC
+++ x.c
@@ -53,6 +53,7 @@ static void clipcopy(const Arg *);
 static void clippaste(const Arg *);
 static void numlock(const Arg *);
 static void selpaste(const Arg *);
+static void swapcolors(const Arg *);
 static void zoom(const Arg *);
 static void zoomabs(const Arg *);
 static void zoomreset(const Arg *);
@@ -240,6 +241,8 @@ static char *opt_title = NULL;
 
 static int oldbutton = 3; /* button event on startup: 3 = release */
 
+int usealtcolors = 0; /* 1 to use alternate palette */
+
 void
 clipcopy(const Arg *dummy)
 {
@@ -279,6 +282,14 @@ numlock(const Arg *dummy)
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
@@ -700,6 +711,11 @@ sixd_to_16bit(int x)
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
@@ -718,7 +734,7 @@ xloadcolor(int i, const char *name, Colo
 			return XftColorAllocValue(xw.dpy, xw.vis,
 			                          xw.cmap, &color, ncolor);
 		} else
-			name = colorname[i];
+			name = getcolorname(i);
 	}
 
 	return XftColorAllocName(xw.dpy, xw.vis, xw.cmap, name, ncolor);
@@ -731,7 +747,7 @@ xloadcols(void)
 	static int loaded;
 	Color *cp;
 
-	dc.collen = MAX(LEN(colorname), 256);
+	dc.collen = MAX(LEN(colorname), LEN(altcolorname));
 	dc.col = xmalloc(dc.collen * sizeof(Color));
 
 	if (loaded) {
@@ -741,8 +757,8 @@ xloadcols(void)
 
 	for (i = 0; i < dc.collen; i++)
 		if (!xloadcolor(i, NULL, &dc.col[i])) {
-			if (colorname[i])
-				die("Could not allocate color '%s'\n", colorname[i]);
+			if (getcolorname(i))
+				die("Could not allocate color '%s'\n", getcolorname(i));
 			else
 				die("Could not allocate color %d\n", i);
 		}
@@ -1079,13 +1095,13 @@ xinit(int cols, int rows)
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
@@ -1295,7 +1311,7 @@ xdrawglyphfontspecs(const XftGlyphFontSp
 
 	/* Change basic system colors [0-7] to bright system colors [8-15] */
 	if ((base.mode & ATTR_BOLD_FAINT) == ATTR_BOLD && BETWEEN(base.fg, 0, 7))
-		fg = &dc.col[base.fg + 8];
+		fg = &dc.col[base.fg];
 
 	if (IS_SET(MODE_REVERSE)) {
 		if (fg == &dc.col[defaultfg]) {
