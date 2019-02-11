--- config.def.h.orig	2019-02-09 12:50:41.000000000 +0100
+++ config.def.h	2019-02-11 13:45:28.209172000 +0100
@@ -84,31 +84,44 @@
 
 /* Terminal colors (16 first used in escape sequence) */
 static const char *colorname[] = {
-	/* 8 normal colors */
-	"black",
-	"red3",
-	"green3",
-	"yellow3",
-	"blue2",
-	"magenta3",
-	"cyan3",
-	"gray90",
-
-	/* 8 bright colors */
-	"gray50",
-	"red",
-	"green",
-	"yellow",
-	"#5c5cff",
-	"magenta",
-	"cyan",
-	"white",
-
-	[255] = 0,
-
-	/* more colors can be added after 255 to use with DefaultXX */
-	"#cccccc",
-	"#555555",
+	/* solarized dark */
+	"#073642",  /*  0: black    */
+	"#dc322f",  /*  1: red      */
+	"#859900",  /*  2: green    */
+	"#b58900",  /*  3: yellow   */
+	"#268bd2",  /*  4: blue     */
+	"#d33682",  /*  5: magenta  */
+	"#2aa198",  /*  6: cyan     */
+	"#eee8d5",  /*  7: white    */
+	"#002b36",  /*  8: brblack  */
+	"#cb4b16",  /*  9: brred    */
+	"#586e75",  /* 10: brgreen  */
+	"#657b83",  /* 11: bryellow */
+	"#839496",  /* 12: brblue   */
+	"#6c71c4",  /* 13: brmagenta*/
+	"#93a1a1",  /* 14: brcyan   */
+	"#fdf6e3",  /* 15: brwhite  */
+};
+ 
+/* Terminal colors for alternate (light) palette */
+static const char *altcolorname[] = {
+	/* solarized light */
+	"#eee8d5",  /*  0: black    */
+	"#dc322f",  /*  1: red      */
+	"#859900",  /*  2: green    */
+	"#b58900",  /*  3: yellow   */
+	"#268bd2",  /*  4: blue     */
+	"#d33682",  /*  5: magenta  */
+	"#2aa198",  /*  6: cyan     */
+	"#073642",  /*  7: white    */
+	"#fdf6e3",  /*  8: brblack  */
+	"#cb4b16",  /*  9: brred    */
+	"#93a1a1",  /* 10: brgreen  */
+	"#839496",  /* 11: bryellow */
+	"#657b83",  /* 12: brblue   */
+	"#6c71c4",  /* 13: brmagenta*/
+	"#586e75",  /* 14: brcyan   */
+	"#002b36",  /* 15: brwhite  */
 };
 
 
@@ -116,10 +129,10 @@
  * Default colors (colorname index)
  * foreground, background, cursor, reverse cursor
  */
-unsigned int defaultfg = 7;
-unsigned int defaultbg = 0;
-static unsigned int defaultcs = 256;
-static unsigned int defaultrcs = 257;
+unsigned int defaultfg = 12;
+unsigned int defaultbg = 8;
+static unsigned int defaultcs = 14;
+static unsigned int defaultrcs = 15;
 
 /*
  * Default shape of cursor
@@ -178,6 +191,7 @@
 	{ TERMMOD,              XK_Y,           selpaste,       {.i =  0} },
 	{ ShiftMask,            XK_Insert,      selpaste,       {.i =  0} },
 	{ TERMMOD,              XK_Num_Lock,    numlock,        {.i =  0} },
+	{ XK_ANY_MOD,           XK_F6,          swapcolors,     {.i =  0} },
 };
 
 /*
