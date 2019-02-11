--- config.def.h.orig	2019-02-09 12:50:41.000000000 +0100
+++ config.def.h	2019-02-11 14:03:37.626887000 +0100
@@ -178,6 +178,8 @@
 	{ TERMMOD,              XK_Y,           selpaste,       {.i =  0} },
 	{ ShiftMask,            XK_Insert,      selpaste,       {.i =  0} },
 	{ TERMMOD,              XK_Num_Lock,    numlock,        {.i =  0} },
+	{ ShiftMask,            XK_Page_Up,     kscrollup,      {.i = -1} },
+	{ ShiftMask,            XK_Page_Down,   kscrolldown,    {.i = -1} },
 };
 
 /*
